
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/CityForceUpdateTypeSuiCallback.h"

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

class CityForceUpdateSuiCallback : public SuiCallback {
	ManagedWeakReference<CityRegion*> cityRegion;

public:
	CityForceUpdateSuiCallback(ZoneServer* server, CityRegion* city);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
