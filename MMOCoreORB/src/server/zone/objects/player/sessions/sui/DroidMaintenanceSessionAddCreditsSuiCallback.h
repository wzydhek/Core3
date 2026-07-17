/*
 * DroidMaintenanceSessionRunMenuSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/DroidMaintenanceSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace sui {

class DroidMaintenanceSessionAddCreditsSuiCallback : public SuiCallback {
public:
	DroidMaintenanceSessionAddCreditsSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::sui;
