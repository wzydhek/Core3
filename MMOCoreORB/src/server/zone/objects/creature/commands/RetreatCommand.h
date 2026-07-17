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

class RetreatCommand : public SquadLeaderCommand {
public:

	RetreatCommand(const String& name, ZoneProcessServer* server);

	bool checkRetreat(CreatureObject* creature) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void doRetreat(CreatureObject* player) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
