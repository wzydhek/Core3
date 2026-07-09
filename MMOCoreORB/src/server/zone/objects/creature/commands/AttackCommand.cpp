#include "AttackCommand.h"

AttackCommand::AttackCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int AttackCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	bool ridingMount = creature->isRidingMount();

	if ((ridingMount && !creature->isSwimming() && !checkStateMask(creature)) || (!ridingMount && !checkStateMask(creature))) {
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature)) {
		return INVALIDLOCOMOTION;
	}

	return doCombatAction(creature, target);
}