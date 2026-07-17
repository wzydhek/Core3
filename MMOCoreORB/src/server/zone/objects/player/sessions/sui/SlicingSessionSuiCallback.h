/*
 * SlicingSessionSuiCallback.h
 *
 *  Created on: Mar 5, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/SlicingSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace sui {

class SlicingSessionSuiCallback : public SuiCallback {
public:
	SlicingSessionSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::sui;
