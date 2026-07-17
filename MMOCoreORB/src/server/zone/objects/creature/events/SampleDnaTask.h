#pragma once

#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/managers/creature/DnaManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class SampleDnaTask : public Task {

private:
	enum Phase { BEGIN, SAMPLING, END} currentPhase;
	int waitCount;
	int originalMask;
	int faction;
	ManagedReference<Creature*> creature;
	ManagedReference<CreatureObject*> player;
public:

	SampleDnaTask(Creature* cre, CreatureObject* playo);

	void resetCreatureStatus();

	void prepareCreatureForSampling();

	void run();

	void killCreature();

	void award(int cl, float rollMod, int skillMod);
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
