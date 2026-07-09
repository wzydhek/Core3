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

class DestroyFactionInstallationTask : public Task {
	ManagedReference<InstallationObject*> installation;

public:
	DestroyFactionInstallationTask(InstallationObject* inst);

	void run();

};
