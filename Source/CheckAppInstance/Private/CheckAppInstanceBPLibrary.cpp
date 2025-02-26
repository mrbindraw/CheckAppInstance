// Copyright 2025 Andrew Bindraw. All Rights Reserved.

#include "CheckAppInstanceBPLibrary.h"
#include "CheckAppInstance.h"

DEFINE_LOG_CATEGORY(LogCheckAppInstanceBPLibrary)

UCheckAppInstanceBPLibrary::UCheckAppInstanceBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UCheckAppInstanceBPLibrary::CheckAnotherAppInstance(bool bIsEnabled)
{
#if !UE_EDITOR
	FString ParseValue;
	if (FParse::Value(FCommandLine::Get(), TEXT("-checkinst="), ParseValue))
	{
		bIsEnabled = ParseValue.ToBool();
	}
	
	if(!bIsEnabled)
	{
		return;
	}

	FCoreDelegates::OnAllModuleLoadingPhasesComplete.AddLambda([]() 
	{	
		// Only one instance of the game can be initialized!
		const UGeneralProjectSettings& ProjectSettings = *GetDefault<UGeneralProjectSettings>();
		const FString LockFilePath = FPlatformProcess::UserTempDir() + ProjectSettings.ProjectID.ToString();
		bool bIsAppInstLaunched = false;

#if PLATFORM_WINDOWS
		bIsAppInstLaunched = (IFileManager::Get().CreateFileWriter(*LockFilePath, 0) == nullptr ? true : false);
#else
		int FileDescriptor = open(TCHAR_TO_UTF8(*LockFilePath), O_CREAT | O_RDWR, 0666); // 0644
		if(FileDescriptor >= 0)
		{
			int CodeFlock = flock(FileDescriptor, LOCK_EX | LOCK_NB);
			if (CodeFlock && errno == EWOULDBLOCK)
			{
				flock(FileDescriptor, LOCK_UN);
				close(FileDescriptor);

				bIsAppInstLaunched = true;
			}
		}
#endif
		UE_LOG(LogCheckAppInstanceBPLibrary, Log, TEXT("LockFilePath: %s, bIsAppInstLaunched: %s"), *LockFilePath, bIsAppInstLaunched ? TEXT("true") : TEXT("false"));
		if (bIsAppInstLaunched)
		{
			FPlatformApplicationMisc::RequestMinimize();
			FPlatformMisc::RequestExit(0);
		}
	});
#endif // !UE_EDITOR
}

