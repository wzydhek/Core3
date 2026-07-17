/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/installation/factory/FactoryObject.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace factory {
namespace tasks {

class CreateFactoryObjectTask : public Task {

	ManagedReference<FactoryObject* > factoryObject;

public:
	CreateFactoryObjectTask(FactoryObject* factory);

	void run();
};

} // namespace tasks
} // namespace factory
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::factory::tasks;
