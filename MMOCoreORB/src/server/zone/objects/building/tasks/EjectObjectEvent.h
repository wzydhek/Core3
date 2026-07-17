/*
 * EjectObjectEvent.h
 *
 *  Created on: 05/10/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace tasks {

class EjectObjectEvent : public Task {
	ManagedReference<SceneObject*> object;
	float x, z, y;

public:
	EjectObjectEvent(SceneObject* obj, float x, float z, float y);

	void run();
};

} // namespace tasks
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::tasks;
