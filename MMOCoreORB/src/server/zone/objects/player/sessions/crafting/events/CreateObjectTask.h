/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/tangible/tool/CraftingTool.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreateObjectTask : public Task {

	ManagedReference<CraftingTool*> craftingTool;
	ManagedReference<CreatureObject*> crafter;
	bool practice;

public:
	CreateObjectTask(CreatureObject* player, CraftingTool* tool, bool pract);

	void run();
};
