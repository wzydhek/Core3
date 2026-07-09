/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"
#include "server/zone/objects/group/GroupObject.h"

class BoostmoraleCommand : public SquadLeaderCommand {
public:

	BoostmoraleCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void getWounds(CreatureObject* leader, GroupObject* group, int* wounds) const;

	bool distributeWounds(CreatureObject* leader, GroupObject* group, int* wounds) const;

};
