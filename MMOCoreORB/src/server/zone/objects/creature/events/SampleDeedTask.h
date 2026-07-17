#pragma once

#include "server/zone/managers/creature/DnaManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/deed/pet/PetDeed.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class SampleDeedTask : public Task {
private:
	enum Phase { BEGIN, SAMPLING, END } currentPhase;
	int waitCount;
	ManagedReference<PetDeed*> deed;
	ManagedReference<CreatureObject*> player;

public:
	SampleDeedTask(PetDeed* obj, CreatureObject* playo);

	void run();

	void award(int cl, float rollMod);
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
