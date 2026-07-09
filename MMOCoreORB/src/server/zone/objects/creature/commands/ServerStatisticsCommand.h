/*
 * ServerStatisticsCommand.h
 *
 *  Created on: Jan 21, 2013
 *      Author: swgemu
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ServerStatisticsCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static void sendSyntax(CreatureObject* player);
};
