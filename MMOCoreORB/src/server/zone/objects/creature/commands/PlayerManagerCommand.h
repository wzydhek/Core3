/*
 * PlayerManagerCommand.h
 *
 *  Created on: 2/28/2012
 *      Author: Kyle
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PlayerManagerCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static void sendSyntax(CreatureObject* player);

	static String dumpCOV(ZoneServer* zoneServer, uint64 oid, bool showAll);

	static String debugTree(CreatureObject* player);
};
