/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class HealBattleFatigueSelf1Command : public ForceHealQueueCommand {
public:

	HealBattleFatigueSelf1Command(const String& name, ZoneProcessServer* server);


};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
