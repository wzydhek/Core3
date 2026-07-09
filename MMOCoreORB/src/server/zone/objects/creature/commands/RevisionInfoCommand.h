/*
 * RevisionInfoCommand.h
 *
 *  Created on: 01/13, 2012
 *      Author: Elvaron
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class RevisionInfoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

};
