#include "ReloadCommand.h"

ReloadCommand::ReloadCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ReloadCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	creature->sendStateCombatSpam("cbt_spam", "reload", 0);

	return SUCCESS;
}