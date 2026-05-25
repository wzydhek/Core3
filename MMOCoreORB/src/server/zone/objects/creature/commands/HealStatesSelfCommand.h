/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealStatesSelfCommand : public ForceHealQueueCommand {
public:

	HealStatesSelfCommand(const String& name, ZoneProcessServer* server)
		: ForceHealQueueCommand(name, server) {

	}
};
