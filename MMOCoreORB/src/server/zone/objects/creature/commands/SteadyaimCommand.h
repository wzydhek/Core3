/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"

class SteadyaimCommand : public SquadLeaderCommand {
public:

	SteadyaimCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool doSteadyAim(CreatureObject* leader, GroupObject* group, int amount) const;

};
