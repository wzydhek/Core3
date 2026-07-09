/*
 * ServerLootCommand.h
 *
 *  Created on: 11/09/2019
 *      Author: Smoki
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/scene/SceneObject.h"

class ServerLootCommand {
	const static int GENERALERROR = 0;
	const static int SUCCESS = 1;

public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static String createLoot(TransactionLog& trx, CreatureObject* creature, SceneObject* container, const String& lootName, int level = 0, float modifier = 0.f);

	static TangibleObject* createLootObject(TransactionLog& trx, CreatureObject* creature, const String& lootName, int level = 0, float modifier = 0.f);

	static String testItem(TransactionLog& trx, CreatureObject* creature, const String& args, bool createItems = true);

	static String testGroup(TransactionLog& trx, CreatureObject* creature, const String& args);

	static String searchLoot(TransactionLog& trx, CreatureObject* creature, const String& args);

	static String agentLoot(TransactionLog& trx, CreatureObject* creature, const String& args);

	 static String getSyntax();

	static void sendSystemMessage(CreatureObject* creature, const String& systemMessage);
};
