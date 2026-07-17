/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class BoostmoraleCommand : public SquadLeaderCommand {
public:

	BoostmoraleCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void getWounds(CreatureObject* leader, GroupObject* group, int* wounds) const;

	bool distributeWounds(CreatureObject* leader, GroupObject* group, int* wounds) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
