/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class TotalHealSelfCommand : public ForceHealQueueCommand {
public:
	TotalHealSelfCommand(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {}
};
