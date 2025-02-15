// Copyright 2025 Andrew Bindraw. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FCheckAppInstanceModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
