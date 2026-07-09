
#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/tangible/deed/pet/PetDeed.h"

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

class PetFixSuiCallback : public SuiCallback {
	ManagedWeakReference<PetControlDevice*> controlDevice;

public:
	PetFixSuiCallback(ZoneServer* server, PetControlDevice* device);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
