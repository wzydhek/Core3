
#pragma once

#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "engine/engine.h"
#include "server/zone/objects/creature/ai/Creature.h"

class MilkCreatureTask : public Task {

private:
	enum Phase { INITIAL, ONESUCCESS, ONEFAILURE, FINAL} currentPhase;
	ManagedReference<Creature*> creature;
	ManagedReference<CreatureObject*> player;

public:
	MilkCreatureTask(Creature* cre, CreatureObject* playo);

	void run();

	void giveMilkToPlayer();

	void clearStationary();

	void updateMilkState(const short milkState);
};
