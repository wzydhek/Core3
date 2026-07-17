/*
 * LightsaberCrystalTuneSuiCallback.h
 *
 *  Created on: Apr 12, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class LightsaberCrystalTuneSuiCallback: public SuiCallback {

public:
	LightsaberCrystalTuneSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
