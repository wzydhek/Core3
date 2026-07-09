/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/structure/StructureObject.h"

class TransferstructureCommand : public QueueCommand {
public:

	TransferstructureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	// pre: creature, targetCreature, and structure are not locked
	// bForceTransfer = whether or not to force the transfer. This means do the transfer even if the target is offline or out of range, or if the old owner is nullptr
	static int doTransferStructure(CreatureObject* creature, CreatureObject* targetCreature, StructureObject* structure, bool bForceTransfer = false);

};

