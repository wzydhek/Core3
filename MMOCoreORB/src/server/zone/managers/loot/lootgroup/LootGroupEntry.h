/*
 * LootGroupEntry.h
 *
 *  Created on: Dec 29, 2011
 *      Author: xyborn
 */

#pragma once

#include "system/lang/String.h"
#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {
namespace lootgroup {

class LootGroupEntry : public Object {
	String templateName;
	int lootChance;

public:
	LootGroupEntry();

	LootGroupEntry(const String& name, int chance);

	LootGroupEntry(const LootGroupEntry& entry);

	void readObject(LuaObject* lua);

	/**
	 * Loot Group Entries are sorted by their weights, in descending order. Thus, the greatest weight will be first.
	 * @param lge The loot group entry to compare.
	 */
	int compareTo(const LootGroupEntry& lge) const;

	LootGroupEntry& operator=(const LootGroupEntry& lge);

	const String& getLootGroupName() const;

	int getLootChance() const;
};

} // namespace lootgroup
} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot::lootgroup;
