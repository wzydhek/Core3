/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CurePackCommand.h"

class CurePoisonCommand : public CurePackCommand {
public:

	CurePoisonCommand(const String& name, ZoneProcessServer* server)
		: CurePackCommand(name, server) {
		state = CreatureState::POISONED;
	}

};
