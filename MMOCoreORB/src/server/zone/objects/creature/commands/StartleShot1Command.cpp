#include "StartleShot1Command.h"

StartleShot1Command::StartleShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int StartleShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}