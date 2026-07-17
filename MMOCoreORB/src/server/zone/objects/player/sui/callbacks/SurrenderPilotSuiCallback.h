
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "templates/faction/Factions.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class SurrenderPilotSuiCallback : public SuiCallback {
	uint32 faction;

public:
	SurrenderPilotSuiCallback(ZoneServer* server, uint32 factionHash);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
