#include "LootGroupEntry.h"

LootGroupEntry::LootGroupEntry() {
	lootChance = 0;
}

LootGroupEntry::LootGroupEntry(const String& name, int chance) {
	templateName = name;
	lootChance = chance;
}

LootGroupEntry::LootGroupEntry(const LootGroupEntry& entry) : Object(), templateName(entry.templateName), lootChance(entry.lootChance) {
}

void LootGroupEntry::readObject(LuaObject* lua) {
	templateName = lua->getStringField("group");
	lootChance = lua->getIntField("chance");
}

/**
 * Loot Group Entries are sorted by their weights, in descending order. Thus, the greatest weight will be first.
 * @param lge The loot group entry to compare.
 */
int LootGroupEntry::compareTo(const LootGroupEntry& lge) const {
	if (lootChance < lge.lootChance)
		return 1;
	else if (lootChance > lge.lootChance)
		return -1;
	else
		return 0;
}

LootGroupEntry& LootGroupEntry::operator=(const LootGroupEntry& lge) {
	if (this == &lge)
		return *this;

	templateName = lge.templateName;
	lootChance = lge.lootChance;

	return *this;
}

const String& LootGroupEntry::getLootGroupName() const {
	return templateName;
}

int LootGroupEntry::getLootChance() const {
	return lootChance;
}