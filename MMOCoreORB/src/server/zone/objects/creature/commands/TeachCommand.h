/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "QueueCommand.h"

class TeachCommand : public QueueCommand {
public:

	TeachCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* teacher, const uint64& target, const UnicodeString& arguments) const;

};

