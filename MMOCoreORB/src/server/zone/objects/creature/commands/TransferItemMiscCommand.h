/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"

class TransferItemMiscCommand : public QueueCommand {
public:
	TransferItemMiscCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	static int doTransferItemMisc(CreatureObject* creature, SceneObject* objectToTransfer, SceneObject* destinationObject, int transferType, TransactionLog& trx);
};

