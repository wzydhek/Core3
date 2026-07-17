/*
 * ContrabandScanTask.h
 *
 *  Created on: Nov 3, 2016
 *      Author: loshult
 */

#pragma once

#include "server/zone/managers/gcw/sessions/ContrabandScanSession.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class ContrabandScanTask : public Task {
	WeakReference<CreatureObject*> weakPlayer;

public:
	ContrabandScanTask(CreatureObject* player);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
