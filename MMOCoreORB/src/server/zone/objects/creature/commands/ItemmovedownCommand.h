/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class ItemmovedownCommand : public QueueCommand {
public:

	ItemmovedownCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

