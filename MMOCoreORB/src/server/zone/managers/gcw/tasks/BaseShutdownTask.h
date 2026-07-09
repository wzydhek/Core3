#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/BaseShutdownSuiCallback.h"

class BaseShutdownTask : public Task {
	ManagedWeakReference<BuildingObject*> building;
	ManagedWeakReference<GCWManager*> gcwMan;
	ManagedWeakReference<CreatureObject*> play;
	ManagedWeakReference<SceneObject*> terminal;

public:
	BaseShutdownTask(GCWManager* gcwManager, BuildingObject* buildingObject, CreatureObject* creature, SceneObject* term);

	void run();
};
