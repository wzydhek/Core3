#include "LootGroupCollectionEntry.h"

LootGroupCollectionEntry::LootGroupCollectionEntry() {
	lootChance = 0;
}

LootGroupCollectionEntry::LootGroupCollectionEntry(const LootGroupCollectionEntry& lgce) : Object() {
	lootGroups = lgce.lootGroups;
	lootChance = lgce.lootChance;
}

LootGroupCollectionEntry& LootGroupCollectionEntry::operator=(const LootGroupCollectionEntry& lgce) {
	if (this == &lgce)
		return *this;

	lootGroups = lgce.lootGroups;
	lootChance = lgce.lootChance;

	return *this;
}

void LootGroupCollectionEntry::readObject(LuaObject* lua, int level) {
	lootChance = lua->getIntField("lootChance");

	if (lootChance == 0) {
		lootChance = 2000000 + (level * 20000); // 20% + (0.2% * level)
	}

	LuaObject luagroups = lua->getObjectField("groups");
	lootGroups.readObject(&luagroups);

	luagroups.pop();
}

int LootGroupCollectionEntry::getLootChance() const {
	return lootChance;
}

const LootGroups* LootGroupCollectionEntry::getLootGroups() const {
	return &lootGroups;
}