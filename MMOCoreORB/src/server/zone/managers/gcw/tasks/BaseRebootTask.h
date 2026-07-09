#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

class BaseRebootTask : public Task {
	ManagedReference<BuildingObject*> buildingObject;
	ManagedReference<GCWManager*> gcwManager;
	Reference<DestructibleBuildingDataComponent*> baseData;

public:
	BaseRebootTask(GCWManager* gcwMan, BuildingObject* building, DestructibleBuildingDataComponent* data);

	void run();
};
