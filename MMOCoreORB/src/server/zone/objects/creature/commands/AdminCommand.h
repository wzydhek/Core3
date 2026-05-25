#pragma once

#include "QueueCommand.h"

class AdminCommand : public QueueCommand {

public:
	AdminCommand(const String& skillName, ZoneProcessServer* serv) : QueueCommand(skillName, serv) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		return SUCCESS;
	}
};
