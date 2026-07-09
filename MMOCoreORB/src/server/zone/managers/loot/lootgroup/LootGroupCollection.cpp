#include "LootGroupCollection.h"

LootGroupCollection::LootGroupCollection() {
}

void LootGroupCollection::readObject(LuaObject* obj, int level) {
	if (!obj->isValidTable())
		return;

	lua_State* L = obj->getLuaState();

	for (int i = 1; i <= obj->getTableSize(); ++i) {
		lua_rawgeti(L, -1, i);

		LuaObject luacollection(L);

		LootGroupCollectionEntry entry;
		entry.readObject(&luacollection, level);

		entries.add(entry);

		luacollection.pop();
	}
}

int LootGroupCollection::count() const {
	return entries.size();
}

const LootGroupCollectionEntry* LootGroupCollection::get(int i) const {
	if (i < 0 || i >= entries.size())
		return nullptr;

	return &entries.get(i);
}