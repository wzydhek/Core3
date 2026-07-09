/*
 * CharacterNameMap.h
 *
 *  Created on: 03/02/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class CharacterNameMap : public Object {
	HashTable<String, uint64> names;
	HashTable<uint64, String> reverseTable;

	ReadWriteLock guard;

public:
	CharacterNameMap();

	void put(CreatureObject* player);

	bool put(const String& name, uint64 oid);

	void remove(const String& name);

	void remove(uint64 oid);

	uint64 get(const String& name);

	String get(uint64 oid);

	bool containsKey(const String& name);

	bool containsOID(uint64 oid);

	int size();

	HashTable<String, uint64> getNames();
};
