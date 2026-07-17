#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class SecurityRepairTask : public Task {

	ManagedReference<TangibleObject*> terminal;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;
	int count;

public:
	SecurityRepairTask(GCWManager* gcwMan, TangibleObject* term, CreatureObject* player, int cnt);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
