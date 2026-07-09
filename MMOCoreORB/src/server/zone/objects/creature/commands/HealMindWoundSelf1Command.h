/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealMindWoundSelf1Command : public ForceHealQueueCommand {
public:

	HealMindWoundSelf1Command(const String& name, ZoneProcessServer* server);
};
