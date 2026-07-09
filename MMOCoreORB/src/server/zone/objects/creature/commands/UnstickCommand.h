/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "QueueCommand.h"

#pragma once

class UnstickCommand : public QueueCommand {
public:

	UnstickCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

