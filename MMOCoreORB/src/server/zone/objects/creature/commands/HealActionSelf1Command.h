/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealActionSelf1Command : public ForceHealQueueCommand {
public:
	HealActionSelf1Command(const String& name, ZoneProcessServer* server);
};
