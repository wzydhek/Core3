/*
 * RelockLootContainer.h
 *
 *  Created on: Mar 10, 2011
 *      Author: polonel
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/tangible/Container.h"

class RelockLootContainerEvent: public Task {
	ManagedReference<Container*> container;

public:
	RelockLootContainerEvent(Container* object);

	void run();

};
