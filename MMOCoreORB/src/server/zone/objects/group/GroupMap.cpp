#include "GroupMap.h"
#include "server/zone/objects/creature/CreatureObject.h"

GroupMap::GroupMap(int initsize) : HashTable<uint64, GroupObject*>(initsize) {
	setNullValue(nullptr);
}

int GroupMap::hash(uint64 const& key) const {
	return Long::hashCode(key);
}