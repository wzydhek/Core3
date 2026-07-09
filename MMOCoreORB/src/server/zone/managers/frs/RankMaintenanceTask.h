#pragma once

#include "server/zone/managers/frs/FrsManager.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace managers {
namespace frs {

class RankMaintenanceTask: public Task {
	ManagedWeakReference<FrsManager*> frsManager;

public:
	RankMaintenanceTask(FrsManager* frs);

	void run();
};

}
}
}
}

using namespace server::zone::managers::frs;
