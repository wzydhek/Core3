/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class TotalHealOtherCommand : public ForceHealQueueCommand {
public:
	TotalHealOtherCommand(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {}
};
