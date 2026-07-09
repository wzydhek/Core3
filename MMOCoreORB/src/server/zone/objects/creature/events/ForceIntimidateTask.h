
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/combat/CreatureAttackData.h"

class ForceIntimidateTask : public Task {
	ManagedReference<CreatureObject*> targetCreature;
	const CreatureAttackData data;
	Reference<SortedVector<ManagedReference<TangibleObject*> >* > targets;

public:
	ForceIntimidateTask(CreatureObject* targetCreo, SortedVector<ManagedReference<TangibleObject*>>* targets, const CombatQueueCommand* command);

	void run();
};
