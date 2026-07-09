#include "Saber2hHit1Command.h"

Saber2hHit1Command::Saber2hHit1Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int Saber2hHit1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}