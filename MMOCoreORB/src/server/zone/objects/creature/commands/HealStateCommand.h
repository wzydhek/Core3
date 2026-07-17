/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/tangible/pharmaceutical/StatePack.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealStateCommand : public QueueCommand {
	float mindCost;
	float range;
	Vector<uint64> healableStates;
public:

	HealStateCommand(const String& name, ZoneProcessServer* server);

	void deactivateStateTreatment(CreatureObject* creature) const;

	void awardXp(CreatureObject* creature, String type, int power) const;

	void sendStateMessage(CreatureObject* creature, CreatureObject* creatureTarget, uint64 state) const;

	void doAnimations(CreatureObject* creature, CreatureObject* creatureTarget) const;

	bool canPerformSkill(CreatureObject* creature, CreatureObject* creatureTarget, StatePack* statePack, int mindCostNew) const;

	StatePack* findStatePack(CreatureObject* creature, uint64 state) const;

	void parseModifier(const String& modifier, uint64& state, uint64& objectId) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
