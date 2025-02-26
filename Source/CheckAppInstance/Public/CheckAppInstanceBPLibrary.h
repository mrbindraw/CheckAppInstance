// Copyright 2025 Andrew Bindraw. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformApplicationMisc.h"
#include "GeneralProjectSettings.h"
#include "Misc/CoreDelegates.h"
#include "Misc/CommandLine.h"

#if PLATFORM_UNIX
#include <unistd.h>		// close
#include <fcntl.h>		// open
#include <sys/file.h>	// flock
#include <errno.h>
#endif

#include "CheckAppInstanceBPLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCheckAppInstanceBPLibrary, Log, All);

UCLASS()
class UCheckAppInstanceBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "CheckAppInstance")
	static void CheckAnotherAppInstance(bool IsEnabled = true);
};
