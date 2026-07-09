/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForceHealQueueCommand.h"

class ForceCureDiseaseCommand : public ForceHealQueueCommand {
public:

	ForceCureDiseaseCommand(const String& name, ZoneProcessServer* server);
};
