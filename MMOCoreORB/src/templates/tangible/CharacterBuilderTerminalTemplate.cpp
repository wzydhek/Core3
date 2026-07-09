#include "CharacterBuilderTerminalTemplate.h"

CharacterBuilderTerminalTemplate::CharacterBuilderTerminalTemplate() : rootNode(nullptr) {
}

CharacterBuilderTerminalTemplate::~CharacterBuilderTerminalTemplate() {
	if (rootNode != nullptr) {
		// delete rootNode;
		rootNode = nullptr;
	}
}

void CharacterBuilderTerminalTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	LuaObject luaGlowyBadges = templateData->getObjectField("glowyBadgeIds");

	for (int i = 1; i <= luaGlowyBadges.getTableSize(); ++i) {
		glowyBadgeIds.add(luaGlowyBadges.getIntAt(i));
	}

	luaGlowyBadges.pop();

	LuaObject luaBranchUnlocks = templateData->getObjectField("villageBranchUnlocks");

	for (int i = 1; i <= luaBranchUnlocks.getTableSize(); ++i) {
		villageBranchUnlocks.add(luaBranchUnlocks.getStringAt(i));
	}

	luaBranchUnlocks.pop();

	LuaObject luaItemList = templateData->getObjectField("itemList");

	// Ensure that the luaItemList root level is of an even order.
	if (luaItemList.getTableSize() % 2 != 0) {
		System::out << "[CharacterBuilderTerminalTemplate] Dimension mismatch in itemList. Item count must be a multiple of 2." << endl;
		luaItemList.pop();
		return;
	}

	rootNode = new CharacterBuilderMenuNode("root");
	rootNode->readLuaObject(luaItemList, true);

	luaItemList.pop();
}

const CharacterBuilderMenuNode* CharacterBuilderTerminalTemplate::getItemList() const {
	return rootNode;
}

const Vector<int>& CharacterBuilderTerminalTemplate::getGlowyBadgeIds() const {
	return glowyBadgeIds;
}

const Vector<String>& CharacterBuilderTerminalTemplate::getVillageBranchUnlocks() const {
	return villageBranchUnlocks;
}