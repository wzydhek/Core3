/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class UnconsentCommand : public QueueCommand {
public:

	UnconsentCommand(const String& name, ZoneProcessServer* server);

	static void unconscent(CreatureObject* player, CreatureObject* targetPlayer);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

