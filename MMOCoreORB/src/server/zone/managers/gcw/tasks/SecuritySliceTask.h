/*
 * SecuritySliceTask.h
 *
 *  Created on: Feb 21, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class SecuritySliceTask : public Task {

	ManagedReference<TangibleObject*> terminal;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;

public:

	SecuritySliceTask(GCWManager* gcwMan, TangibleObject* term, CreatureObject* player);

	void run();
};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
