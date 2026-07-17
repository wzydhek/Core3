/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class RequestSetStatMigrationDataCommand : public QueueCommand {
public:
	RequestSetStatMigrationDataCommand(const String& name, ZoneProcessServer* server);

	static uint32 getMaxAttribute(CreatureObject* creature, uint8 attribute);

	static uint32 getMinAttribute(CreatureObject* creature, uint8 attribute);

	static uint32 getTotalAttribPoints(CreatureObject* creature);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
