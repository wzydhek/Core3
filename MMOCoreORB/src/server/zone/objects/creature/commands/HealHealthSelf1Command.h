/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "ForceHealQueueCommand.h"

class HealHealthSelf1Command : public ForceHealQueueCommand {
public:
	HealHealthSelf1Command(const String& name, ZoneProcessServer* server) : ForceHealQueueCommand(name, server) {}

};
