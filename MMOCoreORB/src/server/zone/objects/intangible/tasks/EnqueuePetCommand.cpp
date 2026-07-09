#include "EnqueuePetCommand.h"

EnqueuePetCommand::EnqueuePetCommand(CreatureObject* pet, uint32 command, const String& args, uint64 target, int priority) {
	this->pet = pet;
	commandCRC = command;
	arguments = args;
	this->target = target;
	this->priority = priority;
}

void EnqueuePetCommand::run() {
	Locker locker(pet);

	pet->enqueueCommand(commandCRC, 0, target, arguments, priority);
}