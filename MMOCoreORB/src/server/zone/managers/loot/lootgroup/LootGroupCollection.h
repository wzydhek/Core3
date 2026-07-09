/*
 * LootGroupCollection.h
 *
 *  Created on: Jan 16, 2012
 *      Author: xyborn
 */

#pragma once

#include "LootGroupCollectionEntry.h"

class LootGroupCollection {
	Vector<LootGroupCollectionEntry> entries;

public:
	LootGroupCollection();

	void readObject(LuaObject* obj, int level);

	int count() const;

	const LootGroupCollectionEntry* get(int i) const;
};
