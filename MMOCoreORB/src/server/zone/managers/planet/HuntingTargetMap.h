/*
 * HuntingTargetMap.h
 *
 *  Created on: Aug 27, 2010
 *      Author: dannuic
 */

#pragma once

#include "engine/engine.h"
#include "HuntingTargetEntry.h"

class HuntingTargetMap :private ReadWriteLock, public Object {
	VectorMap<int, SortedVector<HuntingTargetEntry> > targets;

public:
	HuntingTargetMap();

	void addTarget(const String& temp1, const String& temp2, int lev);

	HuntingTargetEntry* getRandomTarget(int lev);
};
