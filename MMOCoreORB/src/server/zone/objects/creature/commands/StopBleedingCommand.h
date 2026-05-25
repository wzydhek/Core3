/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class StopBleedingCommand : public ForceHealQueueCommand {
public:

	StopBleedingCommand(const String& name, ZoneProcessServer* server)
		: ForceHealQueueCommand(name, server) {

	}
};
