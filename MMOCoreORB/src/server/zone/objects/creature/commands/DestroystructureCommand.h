/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/structure/StructureObject.h"

class DestroystructureCommand : public QueueCommand {
public:

	DestroystructureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int disbandCamp(CreatureObject* creature, StructureObject* structure) const;
};

