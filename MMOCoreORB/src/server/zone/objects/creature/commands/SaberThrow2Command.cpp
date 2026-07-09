#include "SaberThrow2Command.h"

SaberThrow2Command::SaberThrow2Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int SaberThrow2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}