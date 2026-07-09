/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class HealHealthSelf1Command : public ForceHealQueueCommand {
public:
	HealHealthSelf1Command(const String& name, ZoneProcessServer* server);

};
