/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealActionWoundOther2Command : public ForceHealQueueCommand {
public:
	HealActionWoundOther2Command(const String& name, ZoneProcessServer* server);
};
