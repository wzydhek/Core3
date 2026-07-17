/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file ResourceShiftTask.h
 * \author Kyle Burkhardt
 * \date 5-03-10
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/managers/resource/ResourceManager.h"

namespace server {
namespace zone {
namespace managers {
namespace resource {

class ResourceShiftTask : public Task {
	ManagedReference<ResourceManager* > resourceManager;

public:
	ResourceShiftTask(ManagedReference<ResourceManager*> resMan);

	void run();
};

} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource;
