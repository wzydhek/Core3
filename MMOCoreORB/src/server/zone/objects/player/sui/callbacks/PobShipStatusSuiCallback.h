/*
 * PobShipStatusSuiCallback.h
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/ship/PobShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class PobShipStatusSuiCallback : public SuiCallback {
public:
	PobShipStatusSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
