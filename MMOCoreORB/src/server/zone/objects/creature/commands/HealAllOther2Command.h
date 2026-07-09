/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealAllOther2Command : public ForceHealQueueCommand {
public:
	HealAllOther2Command(const String& name, ZoneProcessServer* server);
};
