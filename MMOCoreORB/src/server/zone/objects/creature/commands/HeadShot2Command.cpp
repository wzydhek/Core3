#include "HeadShot2Command.h"

HeadShot2Command::HeadShot2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int HeadShot2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}