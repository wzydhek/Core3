/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"


class CreateCreatureCommand : public QueueCommand {
public:

	CreateCreatureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int createShip(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

