/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class NblastCommand : public CombatQueueCommand {
public:

	NblastCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
