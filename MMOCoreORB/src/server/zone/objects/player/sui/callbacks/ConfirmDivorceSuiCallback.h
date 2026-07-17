/*
 * ConfirmDivorceSuiCallback.h
 *
 *  Created on: 6/8/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class ConfirmDivorceSuiCallback : public SuiCallback {

public:

	ConfirmDivorceSuiCallback(ZoneServer* server);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
