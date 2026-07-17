/*
 * CitySetTaxSuiCallback.h
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

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace callbacks {

class CitySetTaxSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;
	int taxSelected;

public:
	CitySetTaxSuiCallback(ZoneServer* server, CityRegion* city, int tax);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace callbacks
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::callbacks;
