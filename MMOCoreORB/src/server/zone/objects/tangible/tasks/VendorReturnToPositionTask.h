/*
 * VendorReturnToPositionTask.h
 *
 *  Created on: 1/22/2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class VendorReturnToPositionTask : public Task {
	WeakReference<CreatureObject*> vendor;
	float heading;
public:
	VendorReturnToPositionTask(CreatureObject* cr, int va);

	void run();
};
