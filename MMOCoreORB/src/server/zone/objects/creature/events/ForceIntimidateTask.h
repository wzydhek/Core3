
#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/combat/CreatureAttackData.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class ForceIntimidateTask : public Task {
	ManagedReference<CreatureObject*> targetCreature;
	const CreatureAttackData data;
	Reference<SortedVector<ManagedReference<TangibleObject*> >* > targets;

public:
	ForceIntimidateTask(CreatureObject* targetCreo, SortedVector<ManagedReference<TangibleObject*>>* targets, const CombatQueueCommand* command);

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
