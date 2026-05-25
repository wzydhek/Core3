/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CurePackCommand.h"

class ExtinguishFireCommand : public CurePackCommand {
public:

	ExtinguishFireCommand(const String& name, ZoneProcessServer* server)
		: CurePackCommand(name, server) {
		state = CreatureState::ONFIRE;
	}

};
