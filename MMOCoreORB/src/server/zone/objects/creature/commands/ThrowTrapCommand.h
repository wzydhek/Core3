/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "CombatQueueCommand.h"

class ThrowTrapCommand : public CombatQueueCommand {
public:
	ThrowTrapCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;
};
