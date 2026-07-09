//
// Created by theanswer on 6/18/17.
//

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PathFindCommand {
public:
	static int executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments);

	static void sendSyntax(CreatureObject* player);
};
