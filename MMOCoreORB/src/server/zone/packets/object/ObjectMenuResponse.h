/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "RadialMenuItem.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse : public ObjectControllerMessage {
	int listSize;
	uint8 count;

	Reference<RadialMenuItem*> root;

	/*Reference<SceneObject*> player;

	uint64 target;*/

	int indexCount;
	/**
	 * This method is used to write the radial objects to the packet.
	 * \param parentid The parentid of the radial option.
	 * \param radialid The radial id to be handled by the client and radialmanager.
	 * \param callback The callback type for the radial.
	 * \param text The text to label the radial choice.
	 */
	void addRadialOption(RadialMenuItem* item);

public:
	ObjectMenuResponse(SceneObject* player, uint64 target, uint8 counter);

	~ObjectMenuResponse();

	RadialMenuItem* getRadialItem(int index);

	RadialMenuItem* getRadialItemByRadialID(uint8 id);

	void addRadialMenuItem(uint8 parentid, uint8 radialid, uint8 callback, const UnicodeString& text = "");

	/**
	 * Adds an object menu item to the specified parent radial id, not parent index with callback
	 */
	void addRadialMenuItemToRadialID(uint8 parentRadialID, uint8 newRadialID, uint8 callback, const UnicodeString& text = "");

	void addRadialMenuItem(uint8 radialid, uint8 callback, const UnicodeString& text = "");

	void finish();

	void insertRadialItemToMessage(RadialMenuItem* item);

	void setCounter(uint8 counter);

	RadialMenuItem* getRootMenuItem();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
