/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealMindWoundOther2Command : public ForceHealQueueCommand {
public:
	HealMindWoundOther2Command(const String& name, ZoneProcessServer* server);
};
