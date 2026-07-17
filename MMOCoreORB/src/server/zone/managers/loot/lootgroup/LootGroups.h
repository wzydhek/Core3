/*
 * LootGroups.h
 *
 *  Created on: Jan 30, 2012
 *      Author: xyborn
 */

#pragma once

#include "LootGroupEntry.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {
namespace lootgroup {

class LootGroups {
	SortedVector<LootGroupEntry> entries;

public:
	LootGroups();

	void readObject(LuaObject* obj);

	void put(const LootGroupEntry& entry);

	int count() const;

	const LootGroupEntry* get(int idx) const;
};

} // namespace lootgroup
} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot::lootgroup;
