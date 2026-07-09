/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class Bstrike3Command : public CombatQueueCommand {
public:

	Bstrike3Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
