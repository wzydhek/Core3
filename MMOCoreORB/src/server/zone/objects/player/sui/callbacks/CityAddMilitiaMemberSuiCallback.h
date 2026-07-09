/*
 * CityAddMilitiaMemberSuiCallback.h
 *
 *  Created on: Feb 19, 2012
 *      Author: swgemu
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
	class CreatureObject;
}
namespace region {
	class CityRegion;
}
}
}
}

using namespace server::zone::objects::creature;
using namespace server::zone::objects::region;

class CityAddMilitiaMemberSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;

public:
	CityAddMilitiaMemberSuiCallback(ZoneServer* server, CityRegion* city);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
