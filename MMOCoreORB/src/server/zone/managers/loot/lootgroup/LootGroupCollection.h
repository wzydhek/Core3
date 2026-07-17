/*
 * LootGroupCollection.h
 *
 *  Created on: Jan 16, 2012
 *      Author: xyborn
 */

#pragma once

#include "LootGroupCollectionEntry.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {
namespace lootgroup {

class LootGroupCollection {
	Vector<LootGroupCollectionEntry> entries;

public:
	LootGroupCollection();

	void readObject(LuaObject* obj, int level);

	int count() const;

	const LootGroupCollectionEntry* get(int i) const;
};

} // namespace lootgroup
} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot::lootgroup;
