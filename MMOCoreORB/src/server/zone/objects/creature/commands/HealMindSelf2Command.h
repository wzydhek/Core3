/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealMindSelf2Command : public ForceHealQueueCommand {
public:

	HealMindSelf2Command(const String& name, ZoneProcessServer* server);
};
