/*
 * PlayerInfoCommand.h
 *
 *  Created on: 31/03/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PlayerInfoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);
};
