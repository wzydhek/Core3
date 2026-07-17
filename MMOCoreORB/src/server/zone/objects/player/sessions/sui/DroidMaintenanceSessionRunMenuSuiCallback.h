/*
 * DroidMaintenanceSessionRunMenuSuiCallback.h
 *
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/DroidMaintenanceSession.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/structure/StructureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace sui {

class DroidMaintenanceSessionRunMenuSuiCallback : public SuiCallback {
public:
	DroidMaintenanceSessionRunMenuSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::sui;
