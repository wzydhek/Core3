/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/*
 * LogoutServerCommand.h
 *
 *  Created on: Aug 26, 2011
 *      Author: da
 *  Updated on: Sat Oct  8 11:00:07 EDT 2011 by lordkator
 */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class LogoutServerCommand : public QueueCommand {
public:

	LogoutServerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
