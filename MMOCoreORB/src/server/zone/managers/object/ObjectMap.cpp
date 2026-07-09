#include "ObjectMap.h"

ObjectMap::ObjectMap() : objects(3000), maxConnections(50000) {
}

ObjectMap::ObjectMap(int initsize) : objects(initsize), maxConnections(50000) {
}

ManagedReference<SceneObject*> ObjectMap::put(uint64 oid, SceneObject* object) {
	return objects.put(oid, object);
}

ManagedReference<SceneObject*> ObjectMap::remove(uint64 oid) {
	return objects.remove(oid);
}

HashTableIterator<uint64, ManagedReference<SceneObject*>> ObjectMap::iterator() {
	return objects.iterator();
}

HashTable<uint64, ManagedReference<SceneObject*>>* ObjectMap::getMap() {
	return &objects;
}