/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class SteadyaimCommand : public SquadLeaderCommand {
public:

	SteadyaimCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool doSteadyAim(CreatureObject* leader, GroupObject* group, int amount) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
