/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "QueueCommand.h"

#pragma once

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class UnstickCommand : public QueueCommand {
public:

	UnstickCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
