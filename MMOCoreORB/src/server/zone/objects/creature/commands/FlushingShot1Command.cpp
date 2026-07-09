#include "FlushingShot1Command.h"

FlushingShot1Command::FlushingShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FlushingShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}