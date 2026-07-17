/*
 * CustomDroidSuiCallback.h
 *
 *  Created on: 11/29/2013
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"
#include "server/zone/objects/player/sui/callbacks/ColorWithKitSuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class CustomDroidSuiCallback : public SuiCallback, public Logger {
	int numPalette;
	TangibleObject* customizationKit;

public:
	CustomDroidSuiCallback(ZoneServer* serv, int palette, TangibleObject* kitTano);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
