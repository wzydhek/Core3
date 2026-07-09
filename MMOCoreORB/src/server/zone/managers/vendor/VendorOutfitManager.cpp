/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#include "VendorOutfitManager.h"

VendorOutfitManager::VendorOutfitManager() {
}

VendorOutfitManager::~VendorOutfitManager() {
}

void VendorOutfitManager::initialize() {

	setLoggingName("VendorOutfitManager");
	outfits.setNoDuplicateInsertPlan();
	outfits.setNullValue(nullptr);

	loadLuaOutfits();

}

void VendorOutfitManager::loadLuaOutfits() {
	info("Loading Outfits...");
	String outfitName;
	Lua lua;
	lua.init();

	lua.runFile("scripts/mobile/wearables/outfits.lua");

	LuaObject Luaoutfits = lua.getGlobalObject("Outfits");

	for (int i = 1; i < Luaoutfits.getTableSize() + 1; ++i) {
		lua_State* L = Luaoutfits.getLuaState();
		lua_rawgeti(L, -1, i);
		LuaObject outfit(L);

		outfitName = outfit.getStringField("outfitName");

		debug() << "Loaded " << outfitName; // OutfitName
		LuaObject clothing = outfit.getObjectField("clothing"); // Clothing Object

		Reference<Outfit*> oFit = new Outfit();

		for (int j = 1; j <= clothing.getTableSize(); ++j) {
			const auto val = clothing.getStringAt(j);

			debug() << "Added " << val;

			oFit->addClothingCRC(val.hashCode());
		}

		outfits.put(std::move(outfitName), std::move(oFit));

		clothing.pop();

		outfit.pop();
	}

	info(true) << "Loaded " << outfits.size() << " unique outfits";

	Luaoutfits.pop();
}

VectorMap<String, Reference<Outfit*>>* VendorOutfitManager::getOutfits() {
	return &outfits;
}

String& VendorOutfitManager::getOutfitName(int idx) {
	return outfits.elementAt(idx).getKey();
}

Reference<Outfit*> VendorOutfitManager::getOutfit(int idx) {
	return outfits.get(idx);
}

 Reference<Outfit*> VendorOutfitManager::getOutfit(const String& key) {
	return outfits.get(key);
}