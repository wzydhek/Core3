#include "UnarmedDizzy1Command.h"

UnarmedDizzy1Command::UnarmedDizzy1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedDizzy1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}