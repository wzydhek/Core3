/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class RequestSetStatMigrationDataCommand : public QueueCommand {
public:
	RequestSetStatMigrationDataCommand(const String& name, ZoneProcessServer* server);

	static uint32 getMaxAttribute(CreatureObject* creature, uint8 attribute);

	static uint32 getMinAttribute(CreatureObject* creature, uint8 attribute);

	static uint32 getTotalAttribPoints(CreatureObject* creature);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

