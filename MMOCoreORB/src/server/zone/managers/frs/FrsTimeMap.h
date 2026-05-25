//
// Created by Greg Slomin on 5/2/18.
//

#pragma once

#include "engine/engine.h"
#include "system/lang/Time.h"

class FrsTimeMap : public VectorMap<uint64, Time> {
public:
	FrsTimeMap() : VectorMap<uint64, Time>() {
		setNoDuplicateInsertPlan();
	}
};
