/*
 * LuaSuiCallback.h
 *
 *  Created on: Jan 28, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class LuaSuiCallback : public SuiCallback {
	String screenPlay;
	String screenPlayCallback;

public:
	LuaSuiCallback(ZoneServer* zserv, const String& play, const String& callback);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
