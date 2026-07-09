/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealHealthWoundSelf2Command : public ForceHealQueueCommand {
public:

	HealHealthWoundSelf2Command(const String& name, ZoneProcessServer* server);
};
