#include "UnarmedKnockdown2Command.h"

UnarmedKnockdown2Command::UnarmedKnockdown2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedKnockdown2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}