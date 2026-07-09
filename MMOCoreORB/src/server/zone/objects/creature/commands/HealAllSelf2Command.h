/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealAllSelf2Command : public ForceHealQueueCommand {
public:
	HealAllSelf2Command(const String& name, ZoneProcessServer* server);
};
