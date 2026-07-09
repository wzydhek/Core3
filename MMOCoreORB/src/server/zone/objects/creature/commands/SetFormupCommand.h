/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"

class SetFormupCommand : public SquadLeaderCommand {
public:

	SetFormupCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
