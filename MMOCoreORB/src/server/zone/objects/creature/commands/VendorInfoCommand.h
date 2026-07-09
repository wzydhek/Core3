/*
 * VendorInfoCommand.h
 *
 *  Created on: Apr 6, 2011
 *      Author: polonel
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class VendorInfoCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

};
