#include "AdminCommand.h"

AdminCommand::AdminCommand(const String& skillName, ZoneProcessServer* serv) : QueueCommand(skillName, serv) {
}

int AdminCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return SUCCESS;
}