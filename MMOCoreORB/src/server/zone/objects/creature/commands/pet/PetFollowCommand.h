
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetFollowCommand : public QueueCommand {
public:
	PetFollowCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
