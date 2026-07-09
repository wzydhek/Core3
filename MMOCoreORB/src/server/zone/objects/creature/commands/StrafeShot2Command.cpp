#include "StrafeShot2Command.h"

StrafeShot2Command::StrafeShot2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int StrafeShot2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}