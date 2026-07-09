/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealHealthWoundOther1Command : public ForceHealQueueCommand {
public:
	HealHealthWoundOther1Command(const String& name, ZoneProcessServer* server);
};
