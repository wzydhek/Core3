
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetRepairCommand : public QueueCommand {
public:
	PetRepairCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
