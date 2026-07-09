/*
 * DirectorSharedMemory.h
 *
 *  Created on: Jun 1, 2011
 *      Author: theanswer
 */

#pragma once

#include "engine/engine.h"

class DirectorSharedMemory : public Object {
	HashTable<String, uint64> hashTable;
	HashTable<String, String> stringTable;
	HashTable<String, Vector3> vector3Table;
	HashTable<String, Vector<String>> stringVectorTable;

public:
	uint64 get(const String& k) const;

	const String& getString(const String& k) const;

	Vector3 getVector3(const String& k) const;

	Vector<String> getStringVector(const String& k) const;

	void put(const String& k, uint64 v);

	void putString(const String& k, const String& v);

	void putVector3(const String& k, const Vector3& v);

	void putStringVector(const String& k, const Vector<String>& v);

	void remove(const String& k);

	void removeString(const String& k);

	void removeVector3(const String& k);

	void removeStringVector(const String& k);

	void setNullValue(uint64 o);

	Object* clone();

	Object* clone(void* object);
};
