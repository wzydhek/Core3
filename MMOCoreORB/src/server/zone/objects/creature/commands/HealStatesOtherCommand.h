/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealStatesOtherCommand : public ForceHealQueueCommand {
public:

	HealStatesOtherCommand(const String& name, ZoneProcessServer* server);
};
