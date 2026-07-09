#include "MindShot1Command.h"

MindShot1Command::MindShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int MindShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}