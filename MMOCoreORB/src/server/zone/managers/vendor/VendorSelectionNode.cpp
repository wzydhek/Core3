#include "VendorSelectionNode.h"

VendorSelectionNode::VendorSelectionNode() : Object() {
	hiringRequired = 0;
}

VendorSelectionNode::VendorSelectionNode(const VendorSelectionNode& node) : Object() {
	nodeTitle = node.nodeTitle;
	nodePath = node.nodePath;
	suiDisplay = node.suiDisplay;
	hiringRequired = node.hiringRequired;
	childNodes = node.childNodes;
}

VendorSelectionNode& VendorSelectionNode::operator=(const VendorSelectionNode& node) {
	if (this == &node)
		return *this;

	nodeTitle = node.nodeTitle;
	nodePath = node.nodePath;
	suiDisplay = node.suiDisplay;
	hiringRequired = node.hiringRequired;
	childNodes = node.childNodes;

	return *this;
}

void VendorSelectionNode::parseFromLua(LuaObject& lua) {
	if (!lua.isValidTable())
		return;

	nodeTitle = lua.getStringField("nodeName");
	nodePath = lua.getStringField("nodePath");

	if (!lua.getStringField("suiDisplay").isEmpty())
		suiDisplay = lua.getStringField("suiDisplay");

	hiringRequired = lua.getIntField("hiringRequired");

	LuaObject childNodes = lua.getObjectField("childNodes");

	if (childNodes.isValidTable()) {
		for (int i = 1; i < childNodes.getTableSize() + 1; ++i) {
			lua_State* L = lua.getLuaState();
			lua_rawgeti(L, -1, i);
			LuaObject luaNode(L);

			if (luaNode.isValidTable()) {
				Reference<VendorSelectionNode*> childNode = new VendorSelectionNode();
				childNode->parseFromLua(luaNode);

				addChildNode(childNode);
			}

			luaNode.pop();
		}
	}

	childNodes.pop();
}

int VendorSelectionNode::compareTo(const VendorSelectionNode& node) const {
	if (hiringRequired > node.hiringRequired)
		return -1;

	if (hiringRequired < node.hiringRequired)
		return 1;

	return 0;
}

void VendorSelectionNode::addChildNode(VendorSelectionNode* node) {
	childNodes.add(node);
}

void VendorSelectionNode::setNodeName(const String& name) {
	nodeTitle = name;
}

void VendorSelectionNode::setNodePath(const String& path) {
	nodePath = path;
}

void VendorSelectionNode::setHiringRequired(int hiring) {
	hiringRequired = hiring;
}

bool VendorSelectionNode::hasChildNode() {
	return childNodes.size() > 0;
}

void VendorSelectionNode::addChildrenToListBox(SuiListBox* listBox, int hiringSkill) {
	for (int i = 0; i < childNodes.size(); ++i) {
		VendorSelectionNode* child = childNodes.get(i);
		if (child->getHiringRequired() <= hiringSkill)
			listBox->addMenuItem(child->getNodeName(), i);
	}
}

VendorSelectionNode* VendorSelectionNode::getNode(int idx) {
	if (idx < 0 || idx >= childNodes.size())
		return nullptr;

	return childNodes.get(idx);
}

int VendorSelectionNode::getChildNodeSize() {
	return childNodes.size();
}

String VendorSelectionNode::getRandomTemplate(int skillLevel) {
	if (childNodes.size() == 0)
		return "";

	VendorSelectionNode* node = nullptr;
	int loop = 0;

	do {
		node = childNodes.get(System::random(childNodes.size() - 1));
		loop++;
	} while ((node == nullptr || node->getHiringRequired() > skillLevel) && loop < 10);

	if (node == nullptr)
		return "";

	return node->getTemplatePath();
}

String& VendorSelectionNode::getNodeName() {
	return nodeTitle;
}

int VendorSelectionNode::getHiringRequired() {
	return hiringRequired;
}

String& VendorSelectionNode::getSuiDisplay() {
	return suiDisplay;
}

String& VendorSelectionNode::getTemplatePath() {
	return nodePath;
}