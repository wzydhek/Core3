#include "BurstShot2Command.h"

BurstShot2Command::BurstShot2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int BurstShot2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}