/*
 * PetFeedCommand.h
 *
 *  Created on: Jan 19, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

class PetFeedCommand : public QueueCommand {
public:
	PetFeedCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};
