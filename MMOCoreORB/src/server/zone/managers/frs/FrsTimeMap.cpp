#include "FrsTimeMap.h"

FrsTimeMap::FrsTimeMap() : VectorMap<uint64, Time>() {
	setNoDuplicateInsertPlan();
}