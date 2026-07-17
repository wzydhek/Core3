/*
 * RemoveDroidStructureSuiCallback.h
 *
 *  Created on: 1/7/2015
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidMaintenanceModuleDataComponent.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class RemoveDroidStructureSuiCallback : public SuiCallback, public Logger {

	Reference<DroidMaintenanceModuleDataComponent*> module;

public:
	RemoveDroidStructureSuiCallback(ZoneServer* serv, DroidMaintenanceModuleDataComponent* module);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
