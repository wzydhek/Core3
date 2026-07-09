/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class ConsentCommand : public QueueCommand {
public:

	ConsentCommand(const String& name, ZoneProcessServer* server);

	static void consent(CreatureObject* player, CreatureObject* targetPlayer);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

