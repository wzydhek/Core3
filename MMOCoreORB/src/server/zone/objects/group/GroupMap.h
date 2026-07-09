/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "system/util/HashTable.h"
#include "server/zone/objects/group/GroupObject.h"

class GroupMap : public HashTable<uint64, GroupObject*> {
	int hash(uint64 const& key) const override;

public:
	GroupMap(int initsize);

};
