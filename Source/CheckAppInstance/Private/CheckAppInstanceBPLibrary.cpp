// Copyright 2024 Andrew Bindraw. All Rights Reserved.

#include "CheckAppInstanceBPLibrary.h"
#include "CheckAppInstance.h"

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
	
	FCoreDelegates::OnAllModuleLoadingPhasesComplete.AddLambda([bIsEnabled]() 
	{	
		// Only one instance of the game can be initialized!
		const UGeneralProjectSettings& ProjectSettings = *GetDefault<UGeneralProjectSettings>();
		const FString LockFilePath = FPlatformProcess::UserTempDir() + ProjectSettings.ProjectID.ToString();
		if (!IFileManager::Get().CreateFileWriter(*LockFilePath, 0) && bIsEnabled)
		{
			FPlatformApplicationMisc::RequestMinimize();
			FPlatformMisc::RequestExit(0);
		}
	});
#endif
}

