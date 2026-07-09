#include "CitizenList.h"

CitizenList::CitizenList() : SynchronizedSortedVector<uint64>() {
	setNoDuplicateInsertPlan();
}