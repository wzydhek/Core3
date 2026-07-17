/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/objects/tangible/tool/CraftingTool.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {
namespace crafting {
namespace events {

class CreateObjectTask : public Task {
	ManagedReference<CraftingTool*> craftingTool;
	ManagedReference<CreatureObject*> crafter;
	bool practice;

public:
	CreateObjectTask(CreatureObject* player, CraftingTool* tool, bool pract);

	void run();
};

} // namespace events
} // namespace crafting
} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions::crafting::events;
