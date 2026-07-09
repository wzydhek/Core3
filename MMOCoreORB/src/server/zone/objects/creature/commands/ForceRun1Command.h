/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "JediQueueCommand.h"

class ForceRun1Command : public JediQueueCommand {
public:

	ForceRun1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
