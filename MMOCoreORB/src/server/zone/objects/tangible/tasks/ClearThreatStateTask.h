/*
 * ClearThreatStateTask.h
 *
 *  Created on: 1/22/2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class ClearThreatStateTask : public Task {
	ManagedReference<TangibleObject*> self;
	ManagedReference<TangibleObject*> target;
	uint64 state;

public:
	ClearThreatStateTask(TangibleObject* me, TangibleObject* tar, uint64 st) {
		self = me;
		target = tar;
		state = st;
	}

	void run() {
		Locker locker(self);
		ThreatMap* threatMap = self->getThreatMap();
		threatMap->clearThreatState(target, state);
	}
};
