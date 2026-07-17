/*
 * DestroyFactionInstallationTask.h
 *
 *  Created on: Jan 30, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace tasks {

class DestroyFactionInstallationTask : public Task {
	ManagedReference<InstallationObject*> installation;

public:
	DestroyFactionInstallationTask(InstallationObject* inst);

	void run();

};

} // namespace tasks
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::tasks;
