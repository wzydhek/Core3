/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class DelegateFactionPointsCommand : public QueueCommand {
public:

	DelegateFactionPointsCommand(const String& name, ZoneProcessServer* server);

	static int doDelegate(CreatureObject* creature, CreatureObject* targetPlayer, uint32 tipAmount);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

