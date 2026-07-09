#include "Saber1hFlurryCommand.h"

Saber1hFlurryCommand::Saber1hFlurryCommand(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int Saber1hFlurryCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}