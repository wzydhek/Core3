/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class Melee2hHit3Command : public CombatQueueCommand {
public:

	Melee2hHit3Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
