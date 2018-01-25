#pragma once

#include "ModuleManager.h"
#include <Mpc.hpp>

class FVmpcPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};