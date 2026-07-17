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

class ResourceCommand : public QueueCommand {
public:

	ResourceCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void listResources(CreatureObject* creature, StringTokenizer* args) const;

	void healthCheck(CreatureObject* creature, StringTokenizer* args) const;

	void dumpResources(CreatureObject* creature, StringTokenizer* args) const;

	void despawnResource(CreatureObject* creature, StringTokenizer* args) const;

	void listResourceInfo(CreatureObject* creature, StringTokenizer* args) const;

	void findResources(CreatureObject* creature, StringTokenizer* args) const;

	void giveResource(CreatureObject* creature, StringTokenizer* args) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
