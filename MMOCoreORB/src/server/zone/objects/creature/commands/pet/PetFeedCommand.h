/*
 * PetFeedCommand.h
 *
 *  Created on: Jan 19, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace pet {

class PetFeedCommand : public QueueCommand {
public:
	PetFeedCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace pet
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::pet;
