/*
 * LootGroups.h
 *
 *  Created on: Jan 30, 2012
 *      Author: xyborn
 */

#pragma once

#include "LootGroupEntry.h"

class LootGroups {
	SortedVector<LootGroupEntry> entries;

public:
	LootGroups();

	void readObject(LuaObject* obj);

	void put(const LootGroupEntry& entry);

	int count() const;

	const LootGroupEntry* get(int idx) const;
};
