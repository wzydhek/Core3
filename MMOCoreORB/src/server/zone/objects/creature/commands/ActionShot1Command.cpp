#include "ActionShot1Command.h"

ActionShot1Command::ActionShot1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int ActionShot1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}