/*
 * RemoveAggroTask.h
 *
 *  Created on: 1/22/2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class RemoveAggroTask : public Task {
	ManagedReference<TangibleObject*> self;
	ManagedReference<TangibleObject*> target;
	int value;
public:
	RemoveAggroTask(TangibleObject* me, TangibleObject* cr, int va);

	void run();
};
