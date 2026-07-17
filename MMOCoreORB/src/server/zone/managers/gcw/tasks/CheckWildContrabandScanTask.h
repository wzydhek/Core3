/*
 * CheckWildContrabandScanTask.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Loshult
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class CheckWildContrabandScanTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;

public:
	CheckWildContrabandScanTask(GCWManager* manager);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
