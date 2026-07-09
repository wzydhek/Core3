/*
 * LootGroupCollectionEntry.h
 *
 *  Created on: Jan 30, 2012
 *      Author: xyborn
 */

#pragma once

#include "LootGroups.h"
#include "engine/lua/LuaObject.h"

class LootGroupCollectionEntry : public Object {
	LootGroups lootGroups;

	int lootChance;

public:
	LootGroupCollectionEntry();

	LootGroupCollectionEntry(const LootGroupCollectionEntry& lgce);

	LootGroupCollectionEntry& operator=(const LootGroupCollectionEntry& lgce);

	void readObject(LuaObject* lua, int level);

	 int getLootChance() const;

	const LootGroups* getLootGroups() const;
};
