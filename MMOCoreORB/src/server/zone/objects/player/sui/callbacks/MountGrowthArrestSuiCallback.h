
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

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

class MountGrowthArrestSuiCallback : public SuiCallback {
	ManagedWeakReference<PetControlDevice*> controlDevice;

public:
	MountGrowthArrestSuiCallback(ZoneServer* server, PetControlDevice* device);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
