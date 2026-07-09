/*
 * CheckGCWTask.h
 *
 *  Created on: Oct 24, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/Zone.h"

class CheckGCWTask : public Task {
	ManagedWeakReference<GCWManager*> gcwManager;

public:
	CheckGCWTask(GCWManager* manager);

	void run();
};
