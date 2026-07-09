/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediCombatQueueCommand.h"

class Saber2hSweep1Command : public JediCombatQueueCommand {
public:

	Saber2hSweep1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
