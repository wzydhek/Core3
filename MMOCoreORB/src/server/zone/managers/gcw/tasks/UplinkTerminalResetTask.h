#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/building/components/DestructibleBuildingDataComponent.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class UplinkTerminalResetTask : public Task {
	ManagedReference<BuildingObject*> building;
	ManagedReference<GCWManager*> gcwManager;
	Reference<DestructibleBuildingDataComponent*> baseData;

public:
	UplinkTerminalResetTask(BuildingObject* base, GCWManager* gcwMan, DestructibleBuildingDataComponent* bData);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
