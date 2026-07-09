
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetGetPatrolPointCommand : public QueueCommand {
public:
	PetGetPatrolPointCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
