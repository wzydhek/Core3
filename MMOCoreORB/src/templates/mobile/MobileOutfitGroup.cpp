#include "MobileOutfitGroup.h"

MobileOutfitGroup::MobileOutfitGroup() {
}

MobileOutfitGroup::MobileOutfitGroup(const MobileOutfitGroup& o) : Object() {
	outfits = o.outfits;
}

MobileOutfitGroup& MobileOutfitGroup::operator=(const MobileOutfitGroup& o) {
	if (this == &o)
		return *this;

	outfits = o.outfits;

	return *this;
}

void MobileOutfitGroup::readObject(LuaObject* luaObject) {
	// LuaObject outfit = templateData->getObjectField("outfit");

	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		LuaObject obj = luaObject->getObjectAt(i);

		MobileOutfit outfit;
		outfit.readObject(&obj);

		outfits.add(outfit);

		obj.pop();
	}
}

Vector<MobileOutfit>* MobileOutfitGroup::getOutfits() {
	return &outfits;
}