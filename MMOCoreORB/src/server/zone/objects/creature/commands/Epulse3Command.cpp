#include "Epulse3Command.h"

Epulse3Command::Epulse3Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Epulse3Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}