
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetThrowCommand : public QueueCommand {
public:
	PetThrowCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& targetID, const UnicodeString& arguments) const;
};
