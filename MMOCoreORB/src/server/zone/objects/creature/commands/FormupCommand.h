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

class FormupCommand : public SquadLeaderCommand {
public:

	FormupCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool doFormUp(CreatureObject* leader, GroupObject* group) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
