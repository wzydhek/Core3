/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class InspacerrCommand : public CombatQueueCommand {
public:

	InspacerrCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
