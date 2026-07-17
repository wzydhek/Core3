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

class SetRetreatCommand : public SquadLeaderCommand {
public:

	SetRetreatCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, /*Skill* skill,*/ const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
