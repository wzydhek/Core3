/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class HealAllSelf1Command : public ForceHealQueueCommand {
public:

	HealAllSelf1Command(const String& name, ZoneProcessServer* server)
			: ForceHealQueueCommand(name, server) {

	}
};
