/*
 * DonateMineSuiCallback.h
 *
 *  Created on: 2024-08-13
 *  Author: Hakry
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class DonateMineSuiCallback : public SuiCallback {
public:
	DonateMineSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
