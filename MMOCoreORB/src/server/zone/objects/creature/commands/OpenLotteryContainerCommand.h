/*
 * OpenLotteryContainerCommand.h
 *
 *  Created on: Aug 26, 2011
 *      Author: da
 */

#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class OpenLotteryContainerCommand : public QueueCommand {
public:

	OpenLotteryContainerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
