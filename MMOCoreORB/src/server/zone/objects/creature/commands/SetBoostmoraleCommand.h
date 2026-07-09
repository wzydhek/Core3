/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"

class SetBoostmoraleCommand : public SquadLeaderCommand {
public:

	SetBoostmoraleCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
