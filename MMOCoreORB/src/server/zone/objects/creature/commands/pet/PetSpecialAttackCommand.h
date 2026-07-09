
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetSpecialAttackCommand : public QueueCommand {
public:
	PetSpecialAttackCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
