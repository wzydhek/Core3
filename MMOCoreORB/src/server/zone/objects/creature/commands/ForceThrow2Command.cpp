#include "ForceThrow2Command.h"

ForceThrow2Command::ForceThrow2Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceThrow2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}