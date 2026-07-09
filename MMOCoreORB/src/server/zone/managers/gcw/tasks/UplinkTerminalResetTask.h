#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/building/components/DestructibleBuildingDataComponent.h"

class UplinkTerminalResetTask : public Task {
	ManagedReference<BuildingObject*> building;
	ManagedReference<GCWManager*> gcwManager;
	Reference<DestructibleBuildingDataComponent*> baseData;

public:
	UplinkTerminalResetTask(BuildingObject* base, GCWManager* gcwMan, DestructibleBuildingDataComponent* bData);

	void run();
};
