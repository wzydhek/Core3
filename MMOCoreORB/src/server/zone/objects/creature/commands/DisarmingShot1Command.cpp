#include "DisarmingShot1Command.h"

DisarmingShot1Command::DisarmingShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int DisarmingShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}