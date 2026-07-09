#include "LootGroups.h"

LootGroups::LootGroups() {
}

void LootGroups::readObject(LuaObject* obj) {
	if (!obj->isValidTable())
		return;

	lua_State* L = obj->getLuaState();

	for (int i = 1; i <= obj->getTableSize(); ++i) {
		lua_rawgeti(L, -1, i);

		LuaObject luagroup(L);

		LootGroupEntry entry;
		entry.readObject(&luagroup);

		put(entry);

		luagroup.pop();
	}
}

void LootGroups::put(const LootGroupEntry& entry) {
	entries.put(entry);
}

int LootGroups::count() const {
	return entries.size();
}

const LootGroupEntry* LootGroups::get(int idx) const {
	return &entries.get(idx);
}