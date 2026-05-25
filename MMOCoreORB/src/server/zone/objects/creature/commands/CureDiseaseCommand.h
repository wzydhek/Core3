/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CurePackCommand.h"

class CureDiseaseCommand : public CurePackCommand {

public:

	CureDiseaseCommand(const String& name, ZoneProcessServer* server)
		: CurePackCommand(name, server) {

		state = CreatureState::DISEASED;
	}


};
