#include "StoppingShotCommand.h"

StoppingShotCommand::StoppingShotCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int StoppingShotCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}