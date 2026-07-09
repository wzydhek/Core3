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
	CheckWildContrabandScanTask(GCWManager* manager);

	void run();
};
