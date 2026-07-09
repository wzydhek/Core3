#include "AccountMap.h"

AccountMap::AccountMap() : VectorMap<uint32, ManagedReference<Account*>>(), ReadWriteLock("AccountMap") {
	setInsertPlan(VectorMap<uint32, ManagedReference<Account*>>::NO_DUPLICATE);
	setNullValue(nullptr);
}