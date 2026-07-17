/*
 * CheckGCWTask.h
 *
 *  Created on: Oct 24, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class CheckGCWTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;

public:
	CheckGCWTask(GCWManager* manager);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
