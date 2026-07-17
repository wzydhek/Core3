/*
 * RelockLootContainer.h
 *
 *  Created on: Mar 10, 2011
 *      Author: polonel
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/tangible/Container.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class RelockLootContainerEvent: public Task {
	ManagedReference<Container*> container;

public:
	RelockLootContainerEvent(Container* object);

	void run();

};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;
