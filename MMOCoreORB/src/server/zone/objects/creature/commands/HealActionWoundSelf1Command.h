/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealActionWoundSelf1Command : public ForceHealQueueCommand {
public:

	HealActionWoundSelf1Command(const String& name, ZoneProcessServer* server);
};
