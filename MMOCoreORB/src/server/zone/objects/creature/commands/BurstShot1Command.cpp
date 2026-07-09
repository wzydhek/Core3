#include "BurstShot1Command.h"

BurstShot1Command::BurstShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int BurstShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}