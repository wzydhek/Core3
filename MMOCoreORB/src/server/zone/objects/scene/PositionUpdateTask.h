/*
 * PositionUpdateTask.h
 *
 *  Created on: 27/05/2011
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class PositionUpdateTask : public Task {
	ManagedReference<SceneObject*> object;
	ManagedReference<TreeEntry*> entry;
public:
	PositionUpdateTask(SceneObject* obj, TreeEntry* ent);

	void run();
};

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;
