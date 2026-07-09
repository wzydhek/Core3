/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealAllOther1Command : public ForceHealQueueCommand {
public:
	HealAllOther1Command(const String& name, ZoneProcessServer* server);
};
