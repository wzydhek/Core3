/*
 * PetTrickCommand.h
 *
 *  Created on: Dec 18, 2013
 *      Author: TheAnswer
 */

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetTrickCommand : public QueueCommand {
public:
	PetTrickCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
