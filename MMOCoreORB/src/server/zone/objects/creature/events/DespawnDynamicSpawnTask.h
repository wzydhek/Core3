
#pragma once

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DespawnDynamicSpawnTask : public Task {
	ManagedReference<SceneObject*> spawn;

public:
	DespawnDynamicSpawnTask(SceneObject* sceno);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
