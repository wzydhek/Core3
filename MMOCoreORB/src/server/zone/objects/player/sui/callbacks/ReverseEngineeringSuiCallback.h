/*
 * ReverseEngineeringSuiCallback.h
 *
 *  Created on: Jan 25, 2025
 *      Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/ship/components/ShipComponent.h"
#include "server/zone/objects/player/sui/callbacks/NameComponentSuiCallback.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class ReverseEngineeringSuiCallback : public SuiCallback {
public:
	ReverseEngineeringSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
