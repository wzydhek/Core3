/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealBattleFatigueSelf2Command : public ForceHealQueueCommand {
public:

	HealBattleFatigueSelf2Command(const String& name, ZoneProcessServer* server);
};
