/*
 * RenameCitySuiCallback.h
 *
 *  Created on: Sep 2, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/managers/planet/PlanetManager.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class RenameCitySuiCallback : public SuiCallback {
	ManagedWeakReference<Zone*> zne;
	ManagedWeakReference<CityRegion*> city;

public:
	RenameCitySuiCallback(Zone* zone, CityRegion* city);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
