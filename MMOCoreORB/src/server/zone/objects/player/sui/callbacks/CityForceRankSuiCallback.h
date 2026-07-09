
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

class CityForceRankSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;
	bool rankUp;

public:
	CityForceRankSuiCallback(ZoneServer* server, CityRegion* city, bool rank);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
