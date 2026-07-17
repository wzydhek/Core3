/*
 * ShipColorWithKitSuiCallback.h
 *
 * Created on: 2/18/2026
 * Author: Fastburn
*/
#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/tool/ShipPaintKit.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class ShipColorWithKitSuiCallback : public SuiCallback {
	ManagedWeakReference<ShipPaintKit*> customizationKit;

public:
	ShipColorWithKitSuiCallback(ZoneServer* serv, ShipPaintKit* kit);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
