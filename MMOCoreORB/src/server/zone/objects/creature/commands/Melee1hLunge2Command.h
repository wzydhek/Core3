/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class Melee1hLunge2Command : public CombatQueueCommand {
public:

	Melee1hLunge2Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
