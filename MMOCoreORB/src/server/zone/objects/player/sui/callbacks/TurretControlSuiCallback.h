/*
 * TurretControlSuiCallback.h
 *
 *  Created on: Jan 27, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/installation/components/TurretFireTask.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class TurretControlSuiCallback : public SuiCallback {
	ManagedWeakReference<TangibleObject*> turretObject;
	ManagedWeakReference<TangibleObject*> turretControl;
public:
	TurretControlSuiCallback(ZoneServer* server, TangibleObject* turret, TangibleObject* terminal);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
