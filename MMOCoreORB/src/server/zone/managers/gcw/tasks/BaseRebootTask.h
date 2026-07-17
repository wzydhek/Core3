#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class BaseRebootTask : public Task {
	ManagedReference<BuildingObject*> buildingObject;
	ManagedReference<GCWManager*> gcwManager;
	Reference<DestructibleBuildingDataComponent*> baseData;

public:
	BaseRebootTask(GCWManager* gcwMan, BuildingObject* building, DestructibleBuildingDataComponent* data);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
