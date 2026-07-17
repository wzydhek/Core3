/*
 * GamblingSlotPayoutSuiCallback.h
 *
 *  Created on: 04/29, 2012
 *      Author: Elvaron
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/minigames/GamblingManager.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class GamblingSlotPayoutSuiCallback : public SuiCallback {
public:
	GamblingSlotPayoutSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
