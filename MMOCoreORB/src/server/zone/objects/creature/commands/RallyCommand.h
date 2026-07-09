/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"
#include "server/zone/objects/group/GroupObject.h"

class RallyCommand : public SquadLeaderCommand {
public:

	RallyCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool doRally(CreatureObject* leader, GroupObject* group) const;

	void sendRallyCombatSpam(CreatureObject* leader, GroupObject* group, bool success) const;

};
