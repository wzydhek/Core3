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

class DatabaseCommand : public QueueCommand {
public:

	DatabaseCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;


private:
	void doObjectDBQuery(CreatureObject* creature, String db, uint64 objectID) const;

	void doSQLQuery(CreatureObject* creature, String db, uint64 objectID) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
