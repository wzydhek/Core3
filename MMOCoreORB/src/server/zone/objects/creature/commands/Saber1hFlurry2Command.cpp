#include "Saber1hFlurry2Command.h"

Saber1hFlurry2Command::Saber1hFlurry2Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int Saber1hFlurry2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}