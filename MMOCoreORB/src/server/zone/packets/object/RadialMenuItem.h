/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

/**
 * Please see Radial in the wiki for a list of client side radial id's.
 * Also, please note that radial id's are handled in RadialManager.cpp and most have already been defined.
 * Try to find one suitable to your purpose, or piggy back the SERVER_MENUX ones which
 * Call an objects associated virtual method.
 *
 * Callback Types known:
 *  0x01 = Default
 *  0x03 = Callback
 */

namespace server {
namespace zone {
namespace packets {
namespace object {

class RadialMenuItem : public Object {
	uint8 radialID;
	uint8 callback;
	UnicodeString text;

	RadialMenuItem* parent;

	Vector<Reference<RadialMenuItem*> > children;

	int itemIndex;

public:
	RadialMenuItem(int itemidx, RadialMenuItem* parent, uint8 radialid, uint8 callback, const UnicodeString& text = "");

	RadialMenuItem();

	~RadialMenuItem();

	void addRadialMenuItem(int itemidx, uint8 radialid, uint8 callback, const UnicodeString& text = "");

	RadialMenuItem* getItem(int index);

	RadialMenuItem* getItemByRadialID(uint8 index);

	//Setters
	void setRadialID(uint8 radialid);

	void setCallback(uint8 cback);

	void setText(const UnicodeString& txt);

	void setParent(RadialMenuItem* item);

	void setItemIndex(int idx);

	//Getters
	uint8 getRadialID();

	uint8 getCallback();

	UnicodeString& getText();

	RadialMenuItem* getChild(int idx);

	RadialMenuItem* getParent();

	bool hasChildren();

	int getChildrenSize();

	int getParentIndex();

	int getItemIndex();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
