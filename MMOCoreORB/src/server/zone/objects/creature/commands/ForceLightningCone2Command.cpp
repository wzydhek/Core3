#include "ForceLightningCone2Command.h"

ForceLightningCone2Command::ForceLightningCone2Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceLightningCone2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}