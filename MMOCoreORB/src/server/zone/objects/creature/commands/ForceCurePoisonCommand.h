/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "ForceHealQueueCommand.h"

class ForceCurePoisonCommand : public ForceHealQueueCommand {
public:

	ForceCurePoisonCommand(const String& name, ZoneProcessServer* server)
	: ForceHealQueueCommand(name, server) {

	}

};
