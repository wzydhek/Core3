#include "SuppressionFire2Command.h"

SuppressionFire2Command::SuppressionFire2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int SuppressionFire2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}