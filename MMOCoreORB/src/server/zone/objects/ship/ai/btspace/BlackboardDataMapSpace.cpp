#include "BlackboardDataMapSpace.h"

BlackboardDataMapSpace::BlackboardDataMapSpace() {
	setNoDuplicateInsertPlan();
}

BlackboardDataMapSpace::BlackboardDataMapSpace(const BlackboardDataMapSpace& b) : VectorMap<String, BlackboardDataSpace>(b) {
	setNoDuplicateInsertPlan();
}

BlackboardDataMapSpace::~BlackboardDataMapSpace() {
}

BlackboardDataMapSpace& BlackboardDataMapSpace::operator=(const BlackboardDataMapSpace& b) {
	if (this == &b)
		return *this;

	VectorMap<String, BlackboardDataSpace>::operator=(b);
	setNoDuplicateInsertPlan();

	return *this;
}