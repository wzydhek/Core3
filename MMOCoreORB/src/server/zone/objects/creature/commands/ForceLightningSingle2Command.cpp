#include "ForceLightningSingle2Command.h"

ForceLightningSingle2Command::ForceLightningSingle2Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceLightningSingle2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}