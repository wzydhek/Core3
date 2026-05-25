/*
 * CitizenList.h
 *
 *  Created on: Feb 19, 2012
 *      Author: xyborn
 */

#pragma once

#include "engine/engine.h"
#include "system/util/SynchronizedSortedVector.h"

class CitizenList : public SynchronizedSortedVector<uint64> {
public:
	CitizenList() : SynchronizedSortedVector<uint64>() {
		setNoDuplicateInsertPlan();
	}
};
