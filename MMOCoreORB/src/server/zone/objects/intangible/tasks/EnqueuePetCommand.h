/*
 * EnqueuePetCommand.h
 *
 *  Created on: Dec 18, 2013
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/commands/CombatQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace intangible {
namespace tasks {

class EnqueuePetCommand : public Task {
	ManagedReference<CreatureObject*> pet;
	uint32 commandCRC;
	UnicodeString arguments;
	uint64 target;
	int priority;
public:
	EnqueuePetCommand(CreatureObject* pet, uint32 command, const String& args, uint64 target, int priority = QueueCommand::NOCOMBATQUEUE);

	void run();
};

} // namespace tasks
} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible::tasks;
