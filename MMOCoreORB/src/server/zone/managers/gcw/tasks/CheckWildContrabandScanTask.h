/*
 * CheckWildContrabandScanTask.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Loshult
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/Zone.h"

class CheckWildContrabandScanTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;

public:
	CheckWildContrabandScanTask(GCWManager* manager) {
		gcwManager = manager;
	}

	void run() {
		ManagedReference<GCWManager*> strongRef = gcwManager.get();

		if (strongRef == nullptr) {
			return;
		}

		ZoneServer* server = strongRef->getZone()->getZoneServer();

		if (server == nullptr || server->isServerShuttingDown())
			return;

		if (!server->isServerOnline()) {
			uint64 delay = strongRef->getWildScanInterval() + System::random(600000);

			schedule(delay);
			return;
		}

		strongRef->performCheckWildContrabandScanTask();
	}
};
