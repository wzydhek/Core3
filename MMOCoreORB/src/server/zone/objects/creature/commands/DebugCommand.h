/*
 * DebugCommand.h
 *
 *  Created on: Apr 6, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"

class DebugCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

};
