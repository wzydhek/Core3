/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class GetAccountInfoCommand : public QueueCommand {
public:

	GetAccountInfoCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void sendUsage(CreatureObject* creature) const;
};

