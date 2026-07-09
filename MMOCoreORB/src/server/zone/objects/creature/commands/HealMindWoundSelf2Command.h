/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealMindWoundSelf2Command : public ForceHealQueueCommand {
public:

	HealMindWoundSelf2Command(const String& name, ZoneProcessServer* server);
};
