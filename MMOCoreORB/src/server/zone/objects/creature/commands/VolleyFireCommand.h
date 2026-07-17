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

class VolleyFireCommand : public SquadLeaderCommand {
public:

	VolleyFireCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool attemptVolleyFire(CreatureObject* player, uint64* target, int skillMod) const;

	bool doVolleyFire(CreatureObject* leader, GroupObject* group, uint64* target) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
