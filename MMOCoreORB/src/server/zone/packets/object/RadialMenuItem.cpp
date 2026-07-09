#include "RadialMenuItem.h"

RadialMenuItem::RadialMenuItem(int itemidx, RadialMenuItem* parent, uint8 radialid, uint8 callback, const UnicodeString& text) {
	setRadialID(radialid);
	setCallback(callback);
	setText(text);

	RadialMenuItem::parent = parent;

	itemIndex = itemidx;
}

RadialMenuItem::RadialMenuItem() {
	radialID = 0;
	callback = 0;

	itemIndex = 0;

	parent = nullptr;
}

RadialMenuItem::~RadialMenuItem() {
	/*for (int i = 0; i < children.size(); ++i)
		delete children.get(i);*/

	// children.removeAll();
}

void RadialMenuItem::addRadialMenuItem(int itemidx, uint8 radialid, uint8 callback, const UnicodeString& text) {
	RadialMenuItem* menuitem = new RadialMenuItem(itemidx, this, radialid, callback, text);
	children.add(menuitem);
}

RadialMenuItem* RadialMenuItem::getItem(int index) {
	RadialMenuItem* returnItem = nullptr;

	for (int i = 0; i < children.size(); ++i) {
		RadialMenuItem* item = children.get(i);

		if (item->getItemIndex() == index)
			return item;
		else {
			returnItem = item->getItem(index);

			if (returnItem != nullptr)
				return returnItem;
		}
	}

	return returnItem;
}

RadialMenuItem* RadialMenuItem::getItemByRadialID(uint8 index) {
	RadialMenuItem* returnItem = nullptr;

	for (int i = 0; i < children.size(); ++i) {
		RadialMenuItem* item = children.get(i);

		if (item->getRadialID() == index)
			return item;
		else {
			returnItem = item->getItemByRadialID(index);

			if (returnItem != nullptr)
				return returnItem;
		}
	}

	return returnItem;
}

// Setters
void RadialMenuItem::setRadialID(uint8 radialid) {
	radialID = radialid;
}

void RadialMenuItem::setCallback(uint8 cback) {
	callback = cback;
}

void RadialMenuItem::setText(const UnicodeString& txt) {
	text = txt;
}

void RadialMenuItem::setParent(RadialMenuItem* item) {
	parent = item;
}

void RadialMenuItem::setItemIndex(int idx) {
	itemIndex = idx;
}

// Getters
uint8 RadialMenuItem::getRadialID() {
	return radialID;
}

uint8 RadialMenuItem::getCallback() {
	return callback;
}

UnicodeString& RadialMenuItem::getText() {
	return text;
}

RadialMenuItem* RadialMenuItem::getChild(int idx) {
	return children.get(idx);
}

RadialMenuItem* RadialMenuItem::getParent() {
	return parent;
}

bool RadialMenuItem::hasChildren() {
	return children.size() > 0;
}

int RadialMenuItem::getChildrenSize() {
	return children.size();
}

int RadialMenuItem::getParentIndex() {
	if (parent != nullptr) {
		return parent->getItemIndex();
	} else
		return 0;
}

int RadialMenuItem::getItemIndex() {
	return itemIndex;
}