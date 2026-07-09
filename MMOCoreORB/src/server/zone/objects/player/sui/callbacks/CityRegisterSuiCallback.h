/*
 * CityRegisterSuiCallback.h
 *
 *  Created on: Feb 20, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/objects/region/CityRegion.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
	class CreatureObject;
}
}
}
}

using namespace server::zone::objects::creature;

class CityRegisterSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;

	bool unregister;

public:
	CityRegisterSuiCallback(ZoneServer* server, CityRegion* city, bool unregister = false);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
