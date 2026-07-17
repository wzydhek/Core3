
#pragma once

#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/chat/ChatManager.h"
#include "server/zone/objects/creature/events/SpawnCreatureTask.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class TameCreatureTask : public Task {

private:
	enum Phase { INITIAL, SECOND, FINAL} currentPhase;
	int originalMask;
	ManagedWeakReference<Creature*> mob;
	ManagedWeakReference<CreatureObject*> play;
	bool force;
	bool adult;

public:
	TameCreatureTask(Creature* cre, CreatureObject* playo, int pvpMask, bool forced, bool adults);

	void run();

	void success(bool adult);

	void resetStatus();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
