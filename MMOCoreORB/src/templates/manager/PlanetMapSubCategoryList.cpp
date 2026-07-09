#include "PlanetMapSubCategoryList.h"

PlanetMapSubCategoryList::PlanetMapSubCategoryList() : HashTable<int, Reference<PlanetMapSubCategory*>>(256) {
	setNullValue(nullptr);
}

bool PlanetMapSubCategoryList::containsKey(const String& key) const {
	return HashTable<int, Reference<PlanetMapSubCategory*>>::containsKey(key.hashCode());
}

const Reference<PlanetMapSubCategory*>& PlanetMapSubCategoryList::get(const String& key) const {
	return HashTable<int, Reference<PlanetMapSubCategory*>>::get(key.hashCode());
}

const Reference<PlanetMapSubCategory*>& PlanetMapSubCategoryList::get(const int& key) const {
	return HashTable<int, Reference<PlanetMapSubCategory*>>::get(key);
}

Reference<PlanetMapSubCategory*> PlanetMapSubCategoryList::put(const String& key, const Reference<PlanetMapSubCategory*>& value) {
	return HashTable<int, Reference<PlanetMapSubCategory*>>::put(key.hashCode(), value);
}

int PlanetMapSubCategoryList::hash(const int& key) const {
	return key; // this is the string crc so no need to rehash
}

int PlanetMapSubCategoryList::hash(const String& key) const {
	return key.hashCode();
}