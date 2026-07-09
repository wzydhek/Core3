/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/player/sessions/LootLotterySession.h"

namespace server {
namespace zone {
namespace objects {
namespace group {
namespace tasks {

class LootLotteryTimeoutTask : public Task {

	ManagedReference<LootLotterySession*> session;

public:
	LootLotteryTimeoutTask(LootLotterySession* ses);

	void run();

};

} // namespace tasks
} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group::tasks;
