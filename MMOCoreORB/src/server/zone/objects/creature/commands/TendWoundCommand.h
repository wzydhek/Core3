/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "TendCommand.h"

class TendWoundCommand : public TendCommand {
public:

	TendWoundCommand(const String& name, ZoneProcessServer* server)
		: TendCommand(name, server) {
		effectName = "clienteffect/healing_healwound.cef";

		mindCost = 400;
		mindWoundCost = 5;

		woundPool = 1;
		woundsHealed = 25;

		tendWound = true;

		//defaultTime = 5.0;
		range = 6.0;
	}


};
