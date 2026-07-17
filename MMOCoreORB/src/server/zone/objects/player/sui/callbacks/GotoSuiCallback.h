/*
 * GotoSuiCallback.h
 *
 * Created: Sun Feb 28 07:01:21 EST 2016
 *  Author: lordkator
 */

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/waypoint/WaypointObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class GotoSuiCallback : public SuiCallback {

public:
	GotoSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
