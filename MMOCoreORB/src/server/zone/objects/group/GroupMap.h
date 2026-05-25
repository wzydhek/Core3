/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "system/util/HashTable.h"
#include "GroupObject.h"

class GroupMap : public HashTable<uint64, GroupObject*> {
	int hash(uint64 const& key) override {
        	return Long::hashCode(key);
	}

public:
	GroupMap(int initsize) : HashTable<uint64, GroupObject*>(initsize) {
		setNullValue(nullptr);
	}

};
