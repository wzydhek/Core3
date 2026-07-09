/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealHealthWoundOther2Command : public ForceHealQueueCommand {
public:
	HealHealthWoundOther2Command(const String& name, ZoneProcessServer* server);
};
