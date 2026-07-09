#include "Epulse2Command.h"

Epulse2Command::Epulse2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Epulse2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}