/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "JediQueueCommand.h"

class ForceRun2Command : public JediQueueCommand {
public:
	ForceRun2Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
