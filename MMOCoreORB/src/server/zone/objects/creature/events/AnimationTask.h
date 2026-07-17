/*
 * AnimationTask.h
 *
 *  Created on: 08/08/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class AnimationTask : public Task {
	ManagedReference<CreatureObject*> creature;
	String animation;
public:
	AnimationTask(CreatureObject* creo, const String& anim);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
