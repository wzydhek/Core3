#include "PolearmLegHit3Command.h"

PolearmLegHit3Command::PolearmLegHit3Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int PolearmLegHit3Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}