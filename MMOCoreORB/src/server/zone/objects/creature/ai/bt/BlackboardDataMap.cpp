#include "BlackboardDataMap.h"

BlackboardDataMap::BlackboardDataMap() {
	setNoDuplicateInsertPlan();
}

BlackboardDataMap::BlackboardDataMap(const BlackboardDataMap& b) : VectorMap<String, BlackboardData>(b) {
	setNoDuplicateInsertPlan();
}

BlackboardDataMap::~BlackboardDataMap() {
}

BlackboardDataMap& BlackboardDataMap::operator=(const BlackboardDataMap& b) {
	if (this == &b)
		return *this;

	VectorMap<String, BlackboardData>::operator=(b);
	setNoDuplicateInsertPlan();

	return *this;
}