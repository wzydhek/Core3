#include "PlanetMapCategoryList.h"

PlanetMapCategoryList::PlanetMapCategoryList() : HashTable<int, Reference<PlanetMapCategory*>>(256) {
	setNullValue(nullptr);
}

bool PlanetMapCategoryList::containsKey(const String& key) const {
	return HashTable<int, Reference<PlanetMapCategory*>>::containsKey(key.hashCode());
}

const Reference<PlanetMapCategory*>& PlanetMapCategoryList::get(const String& key) const {
	return HashTable<int, Reference<PlanetMapCategory*>>::get(key.hashCode());
}

const Reference<PlanetMapCategory*>& PlanetMapCategoryList::get(const int& key) const {
	return HashTable<int, Reference<PlanetMapCategory*>>::get(key);
}

Reference<PlanetMapCategory*> PlanetMapCategoryList::put(const String& key, const Reference<PlanetMapCategory*>& value) {
	return HashTable<int, Reference<PlanetMapCategory*>>::put(key.hashCode(), value);
}

int PlanetMapCategoryList::hash(const int& key) const {
	return key; // this is the string crc so no need to rehash
}

int PlanetMapCategoryList::hash(const String& key) const {
	return key.hashCode();
}