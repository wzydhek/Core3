#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/BaseShutdownSuiCallback.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class BaseShutdownTask : public Task {
	ManagedWeakReference<BuildingObject*> building;
	ManagedWeakReference<GCWManager*> gcwMan;
	ManagedWeakReference<CreatureObject*> play;
	ManagedWeakReference<SceneObject*> terminal;

public:
	BaseShutdownTask(GCWManager* gcwManager, BuildingObject* buildingObject, CreatureObject* creature, SceneObject* term);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
