#include "FastBlastCommand.h"

FastBlastCommand::FastBlastCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FastBlastCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	UnicodeString args = "healthDamageMultiplier=0.33f;actionDamageMultiplier=0.33f;mindDamageMultiplier=0.33f;";

	return doCombatAction(creature, target, args);
}