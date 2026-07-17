/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/structure/StructureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class DestroystructureCommand : public QueueCommand {
public:

	DestroystructureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int disbandCamp(CreatureObject* creature, StructureObject* structure) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
