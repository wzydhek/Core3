/*
 * ServerWhoCommand.h
 *
 *  Created on: Sat Jul  6 18:10:48 UTC 2019
 *      Author: lordkator
 */

#pragma once

#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class ServerWhoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static void sendSyntax(CreatureObject* player);
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
