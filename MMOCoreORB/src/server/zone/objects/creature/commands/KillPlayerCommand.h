/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class KillPlayerCommand : public QueueCommand {
public:
	KillPlayerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int killPlayerShip(CreatureObject* creature, const uint64& targetID, const UnicodeString& arguments) const;
};

