/*
 * ServerInfoCommand.h
 *
 *  Created on: 31/03/2011
 *      Author: xyborn
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ServerInfoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static void sendSyntax(CreatureObject* player);
};
