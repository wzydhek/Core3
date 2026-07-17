/*
 * RemoveAggroTask.h
 *
 *  Created on: 1/22/2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class RemoveAggroTask : public Task {
	ManagedReference<TangibleObject*> self;
	ManagedReference<TangibleObject*> target;
	int value;
public:
	RemoveAggroTask(TangibleObject* me, TangibleObject* cr, int va);

	void run();
};

} // namespace tasks
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tasks;
