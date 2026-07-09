/*
 * ContrabandScanTask.h
 *
 *  Created on: Nov 3, 2016
 *      Author: loshult
 */

#pragma once

#include "server/zone/managers/gcw/sessions/ContrabandScanSession.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ContrabandScanTask : public Task {
	WeakReference<CreatureObject*> weakPlayer;

public:
	ContrabandScanTask(CreatureObject* player);

	void run();
};
