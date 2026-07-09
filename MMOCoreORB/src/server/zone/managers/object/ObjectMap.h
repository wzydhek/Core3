/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/SceneObject.h"

class ObjectMap : public Object {
	HashTable<uint64, ManagedReference<SceneObject*> > objects;

	int maxConnections;

public:
	ObjectMap();

	ObjectMap(int initsize);

	ManagedReference<SceneObject*> put(uint64 oid, SceneObject* object);

	ManagedReference<SceneObject*> remove(uint64 oid);

	HashTableIterator<uint64, ManagedReference<SceneObject*>> iterator();

	HashTable<uint64, ManagedReference<SceneObject*>>* getMap();
};
