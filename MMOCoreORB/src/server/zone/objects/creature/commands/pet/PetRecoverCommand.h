/*
 * PetRecoverCommand.h
 *
 *  Created on: Feb 23, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetRecoverCommand : public QueueCommand {
public:
	PetRecoverCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
