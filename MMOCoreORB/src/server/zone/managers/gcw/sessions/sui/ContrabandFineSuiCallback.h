/*
 * ContrabandFineSuiCallback.h
 *
 *  Created on: nov 30, 2016
 *      Author: loshult
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/sessions/ContrabandScanSession.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {
namespace sessions {
namespace sui {

class ContrabandFineSuiCallback : public SuiCallback {
public:
	ContrabandFineSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace sessions
} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw::sessions::sui;
