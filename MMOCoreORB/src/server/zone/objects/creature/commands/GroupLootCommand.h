/*
 * GroupLootCommand.h
 *
 *  Modified on: March 2, 2015
 *      Author: Anakis
 */

#pragma once

#include "QueueCommand.h"

class GroupLootCommand : public QueueCommand {
public:

	GroupLootCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

