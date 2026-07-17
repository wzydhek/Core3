/*
 * WildContrabandScanTask.h
 *
 *  Created on: Aug 30, 2020
 *      Author: loshult
 */

#pragma once

#include "server/zone/managers/gcw/sessions/WildContrabandScanSession.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class WildContrabandScanTask : public Task {
	WeakReference<CreatureObject*> weakPlayer;

public:
	WildContrabandScanTask(CreatureObject* player);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
