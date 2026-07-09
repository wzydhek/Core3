#pragma once

#include "server/zone/managers/frs/FrsManager.h"

namespace server {
namespace zone {
namespace managers {
namespace frs {

class VoteStatusTask: public Task {
	ManagedWeakReference<FrsManager*> frsManager;

public:
	VoteStatusTask(FrsManager* frs);

	void run();
};

}
}
}
}

using namespace server::zone::managers::frs;
