/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"

class FlourishCommand: public QueueCommand {
public:

	FlourishCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	float getCommandDuration(CreatureObject* creature, const UnicodeString& arguments) const;

};

