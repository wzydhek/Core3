#include "Melee1hBodyHit3Command.h"

Melee1hBodyHit3Command::Melee1hBodyHit3Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee1hBodyHit3Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}