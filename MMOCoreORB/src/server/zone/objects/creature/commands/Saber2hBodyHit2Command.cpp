#include "Saber2hBodyHit2Command.h"

Saber2hBodyHit2Command::Saber2hBodyHit2Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int Saber2hBodyHit2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}