// Copyright (C) 2017  Runeberg (github: 1runeberg, UE4 Forums: runeberg)

/*
The MIT License (MIT)
Copyright (c) 2017 runeberg (github: 1runeberg, UE4 Forums: runeberg)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "VmpcPlugin.h"
#include <Logger.hpp>
#include <sequencer/Sequencer.hpp>
#include <sequencer/Sequence.hpp>
#include <disk/AbstractDisk.hpp>
#include <file/all/AllLoader.hpp>
#include <file/aps/ApsLoader.hpp>

#include <thread>

#define LOCTEXT_NAMESPACE "FVmpcPluginModule"

void FVmpcPluginModule::StartupModule()
{
	moduru::Logger::l.log("StartupModule\n");
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	mpcInstance = std::make_shared<mpc::Mpc>();
	mpcInstance->init("unreal");
	auto sequencer = mpcInstance->getSequencer().lock();
	auto sequence = sequencer->getActiveSequence().lock();

	mpcInstance->getDisk().lock()->moveForward("TEST2");
	mpcInstance->getDisk().lock()->initFiles();
	mpc::disk::MpcFile* f = mpcInstance->getDisk().lock()->getFile("FRUTZLE.ALL");
	auto allLoader = new mpc::file::all::AllLoader(mpcInstance.get(), f);
	f = mpcInstance->getDisk().lock()->getFile("FRUTZLE.APS");
	auto apsLoader = new mpc::file::aps::ApsLoader(mpcInstance.get(), f);
	delete allLoader;
	while (mpcInstance->getDisk().lock()->isBusy()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	delete apsLoader;
	sequencer->playFromStart();
}

void FVmpcPluginModule::ShutdownModule()
{
	moduru::Logger::l.log("ShutdownModule\n");
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	mpcInstance.reset();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVmpcPluginModule, VmpcPlugin)
