/*
 * PetEmoteCommand.h
 *
 *  Created on: Jan 28, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/intangible/PetControlDevice.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace pet {

class PetEmoteCommand : public QueueCommand {
public:
	PetEmoteCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int praise(AiAgent* pet) const;

	int shame(AiAgent* pet) const;

	int alert(AiAgent* pet) const;

	int summon(AiAgent* pet, PetControlDevice* controlDevice) const;
};

} // namespace pet
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::pet;
