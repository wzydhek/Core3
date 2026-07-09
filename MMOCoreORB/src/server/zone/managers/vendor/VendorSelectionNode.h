/*
 * VendorSelectionNode.h
 *
 *  Created on: Mar 23, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

class VendorSelectionNode : public Object {

	String nodeTitle;
	String nodePath;
	String suiDisplay;
	int hiringRequired;

	SortedVector<Reference<VendorSelectionNode*> > childNodes;

public:
	VendorSelectionNode();

	VendorSelectionNode(const VendorSelectionNode& node);

	VendorSelectionNode& operator=(const VendorSelectionNode& node);

	void parseFromLua(LuaObject& lua);

	int compareTo(const VendorSelectionNode& node) const;

	void addChildNode(VendorSelectionNode* node);

	void setNodeName(const String& name);

	void setNodePath(const String& path);

	void setHiringRequired(int hiring);

	bool hasChildNode();

	void addChildrenToListBox(SuiListBox* listBox, int hiringSkill);

	VendorSelectionNode* getNode(int idx);

	int getChildNodeSize();

	String getRandomTemplate(int skillLevel);

	String& getNodeName();

	int getHiringRequired();

	String& getSuiDisplay();

	String& getTemplatePath();

};
