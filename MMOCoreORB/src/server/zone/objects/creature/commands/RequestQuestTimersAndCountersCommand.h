/*
 * RequestQuestTimersAndCountersCommand.h
 *
 *  Created on: Oct 6, 2010
 *      Author: oru
 */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class RequestQuestTimersAndCountersCommand : public QueueCommand {
public:

	RequestQuestTimersAndCountersCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
