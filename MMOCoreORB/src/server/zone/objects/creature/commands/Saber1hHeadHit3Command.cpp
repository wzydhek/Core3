#include "Saber1hHeadHit3Command.h"

Saber1hHeadHit3Command::Saber1hHeadHit3Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int Saber1hHeadHit3Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}