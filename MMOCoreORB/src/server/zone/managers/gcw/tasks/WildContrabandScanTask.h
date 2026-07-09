/*
 * WildContrabandScanTask.h
 *
 *  Created on: Aug 30, 2020
 *      Author: loshult
 */

#pragma once

#include "server/zone/managers/gcw/sessions/WildContrabandScanSession.h"
#include "server/zone/objects/creature/CreatureObject.h"

class WildContrabandScanTask : public Task {
	WeakReference<CreatureObject*> weakPlayer;

public:
	WildContrabandScanTask(CreatureObject* player);

	void run();
};
