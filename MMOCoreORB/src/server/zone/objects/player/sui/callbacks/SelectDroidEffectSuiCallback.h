/*
 * SelectDroidEffectSuiCallback.h
 *
 *  Created on: 11/28/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidEffectsModuleDataComponent.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/objects/player/sui/callbacks/SelectDroidEffectDelaySuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class SelectDroidEffectSuiCallback : public SuiCallback, public Logger {

	Reference<DroidEffectsModuleDataComponent*> module;
	int slotIndex;

public:
	SelectDroidEffectSuiCallback(ZoneServer* serv, DroidEffectsModuleDataComponent* module, int slotIndex);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
