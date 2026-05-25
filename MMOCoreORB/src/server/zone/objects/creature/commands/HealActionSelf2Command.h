/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "ForceHealQueueCommand.h"

class HealActionSelf2Command : public ForceHealQueueCommand {
public:
	HealActionSelf2Command(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {}
};
