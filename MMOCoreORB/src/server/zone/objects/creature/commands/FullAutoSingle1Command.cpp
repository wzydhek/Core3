#include "FullAutoSingle1Command.h"

FullAutoSingle1Command::FullAutoSingle1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FullAutoSingle1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}