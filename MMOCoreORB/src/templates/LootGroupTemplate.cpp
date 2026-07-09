#include "LootGroupTemplate.h"

LootGroupTemplate::LootGroupTemplate(const String& name) {
	templateName = name;

	entryMap.setNoDuplicateInsertPlan();
	entryMap.setNullValue(0);
}

LootGroupTemplate::LootGroupTemplate(const LootGroupTemplate& lgt) : Object() {
	templateName = lgt.templateName;

	entryMap.setNoDuplicateInsertPlan();
	entryMap.setNullValue(0);

	entryMap = lgt.entryMap;
}

LootGroupTemplate& LootGroupTemplate::operator=(const LootGroupTemplate& lgt) {
	if (this == &lgt)
		return *this;

	templateName = lgt.templateName;
	entryMap = lgt.entryMap;

	return *this;
}

String LootGroupTemplate::getLootGroupEntryForRoll(int roll) const {
	int totalChance = 0;

	for (int i = 0; i < entryMap.size(); ++i) {
		VectorMapEntry<String, int>* entry = &entryMap.elementAt(i);
		int weight = entry->getValue();

		totalChance += weight;

		if (totalChance >= roll && weight > 0)
			return entry->getKey();
	}

	// Should never get here unless the scripts didn't add up to 10000000.
	return "";
}

int LootGroupTemplate::getLootGroupIntEntryForRoll(int roll) const {
	int totalChance = 0;

	for (int i = 0; i < entryMap.size(); ++i) {
		VectorMapEntry<String, int>* entry = &entryMap.elementAt(i);
		int weight = entry->getValue();
		totalChance += weight;

		if (totalChance >= roll && weight > 0)
			return i;
	}

	// Should never get here unless the scripts didn't add up to 10000000.
	return -1;
}

int LootGroupTemplate::size() const {
	return entryMap.size();
}

String LootGroupTemplate::getLootGroupEntryAt(int i) const {
	if (i < 0)
		return "";

	if (i >= entryMap.size())
		return "";

	VectorMapEntry<String, int>* entry = &entryMap.elementAt(i);
	return entry->getKey();
}

void LootGroupTemplate::readObject(LuaObject* lua) {
	LuaObject lootItems = lua->getObjectField("lootItems");

	if (!lootItems.isValidTable())
		return;

	lua_State* L = lua->getLuaState();

	for (int i = 1; i <= lootItems.getTableSize(); ++i) {
		lua_rawgeti(L, -1, i);
		LuaObject lootItem(L);

		String itemTemplate = lootItem.getStringField("itemTemplate");
		String groupTemplate = lootItem.getStringField("groupTemplate");
		int chance = lootItem.getIntField("weight");

		if (itemTemplate.isEmpty())
			entryMap.put(groupTemplate, chance);
		else
			entryMap.put(itemTemplate, chance);

		lootItem.pop();
	}

	lootItems.pop();
}

const String& LootGroupTemplate::getTemplateName() const {
	return templateName;
}