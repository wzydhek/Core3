#include "ShuttleMap.h"

ShuttleMap::ShuttleMap() : VectorMap<uint64, Reference<ShuttleDepartureTask*>>() {
	setNoDuplicateInsertPlan();
	setNullValue(nullptr);
}