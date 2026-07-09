
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetHarvestCommand : public QueueCommand {
public:
	PetHarvestCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& targetID, const UnicodeString& arguments) const;
};
