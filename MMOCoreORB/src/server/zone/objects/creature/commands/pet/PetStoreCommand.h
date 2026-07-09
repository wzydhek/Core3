
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetStoreCommand : public QueueCommand {
public:
	PetStoreCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
