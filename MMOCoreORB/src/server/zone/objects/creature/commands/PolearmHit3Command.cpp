#include "PolearmHit3Command.h"

PolearmHit3Command::PolearmHit3Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int PolearmHit3Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}