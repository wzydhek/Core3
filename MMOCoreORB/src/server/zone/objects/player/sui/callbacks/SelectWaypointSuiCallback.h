/*
 * SelectDroidEffectSuiCallback.h
 *
 *  Created on: 11/28/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidMerchantModuleDataComponent.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class SelectWaypointSuiCallback : public SuiCallback, public Logger {

	Reference<DroidMerchantModuleDataComponent*> module;
	int slotIndex;

public:
	SelectWaypointSuiCallback(ZoneServer* serv, DroidMerchantModuleDataComponent* module);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
