#include "CharacterBuilderMenuNode.h"

CharacterBuilderMenuNode::CharacterBuilderMenuNode(const String& name) {
	displayName = name;
	parentNode = nullptr;
	templateCRC = 0;
	childNodes.setInsertPlan(SortedVector<CharacterBuilderMenuNode*>::NO_DUPLICATE);
}

CharacterBuilderMenuNode::CharacterBuilderMenuNode(const String& name, const String& tplPath) {
	parentNode = nullptr;
	displayName = name;
	templatePath = tplPath;
	templateCRC = tplPath.hashCode();
	childNodes.setInsertPlan(SortedVector<CharacterBuilderMenuNode*>::NO_DUPLICATE);
}

int CharacterBuilderMenuNode::readLuaObject(LuaObject& luaObject, bool recursive) {
	int tableSize = luaObject.getTableSize();

	if (tableSize % 2 != 0)
		return 0;

	for (int i = 1; i <= tableSize; i += 2) {
		String title = luaObject.getStringAt(i);

		lua_State* L = luaObject.getLuaState();
		lua_rawgeti(L, -1, i + 1);
		LuaObject a(L);

		CharacterBuilderMenuNode* node = new CharacterBuilderMenuNode(title);
		node->setParentNode(this);

		if (a.isValidTable()) {
			node->readLuaObject(a, true);
			a.pop();
		} else {
			a.pop();
			node->setTemplatePath(luaObject.getStringAt(i + 1));
		}

		childNodes.put(node);
	}

	return 0;
}

int CharacterBuilderMenuNode::compareTo(CharacterBuilderMenuNode* obj) {
	return displayName.compareTo(obj->getDisplayName());
}

void CharacterBuilderMenuNode::setTemplatePath(const String& tplPath) {
	templatePath = tplPath;
	templateCRC = tplPath.hashCode();
}

void CharacterBuilderMenuNode::setParentNode(CharacterBuilderMenuNode* parent) {
	parentNode = parent;
}

CharacterBuilderMenuNode* CharacterBuilderMenuNode::getParentNode() {
	return parentNode.get().get();
}

const CharacterBuilderMenuNode* CharacterBuilderMenuNode::getParentNode() const {
	return parentNode.get().get();
}

bool CharacterBuilderMenuNode::hasParentNode() const {
	return parentNode.get() != nullptr;
}

bool CharacterBuilderMenuNode::hasChildNodes() const {
	return childNodes.size() > 0;
}

const String& CharacterBuilderMenuNode::getDisplayName() const {
	return displayName;
}

const String& CharacterBuilderMenuNode::getTemplatePath() const {
	return templatePath;
}

uint32 CharacterBuilderMenuNode::getTemplateCRC() const {
	return templateCRC;
}

int CharacterBuilderMenuNode::getChildNodeSize() const {
	return childNodes.size();
}

const CharacterBuilderMenuNode* CharacterBuilderMenuNode::getChildNodeAt(int index) const {
	if (childNodes.size() < index + 1 || index < 0)
		return nullptr;

	return childNodes.get(index);
}

CharacterBuilderMenuNode* CharacterBuilderMenuNode::getChildNodeAt(int index) {
	if (childNodes.size() < index + 1 || index < 0)
		return nullptr;

	return childNodes.get(index);
}