#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/frs/FrsManager.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class EnclaveCouncilRankSuiCallback : public SuiCallback {
private:
	int councilType;
public:
	EnclaveCouncilRankSuiCallback(ZoneServer* server, int type);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
