/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "ServerCommandFactory.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class ServerCommand : public QueueCommand {
	MethodFactory<String, CreatureObject*, uint64, const String&> methodFactory;

public:

	ServerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
