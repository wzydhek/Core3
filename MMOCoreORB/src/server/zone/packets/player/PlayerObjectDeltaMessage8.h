/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectDeltaMessage8 : public DeltaMessage {
	PlayerObjectImplementation* play;

public:
	PlayerObjectDeltaMessage8(PlayerObjectImplementation* pl);

	void updateForcePower();

	void updateForcePowerMax();
};
