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

class EnqueuePetCommand : public Task {
	ManagedReference<CreatureObject*> pet;
	uint32 commandCRC;
	UnicodeString arguments;
	uint64 target;
	int priority;
public:
	EnqueuePetCommand(CreatureObject* pet, uint32 command, const String& args, uint64 target, int priority = QueueCommand::NOCOMBATQUEUE) {
		this->pet = pet;
		commandCRC = command;
		arguments = args;
		this->target = target;
		this->priority = priority;
	}

	void run() {
		Locker locker(pet);

		pet->enqueueCommand(commandCRC, 0, target, arguments, priority);
	}
};
