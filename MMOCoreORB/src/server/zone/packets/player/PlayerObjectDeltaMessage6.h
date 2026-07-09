/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectDeltaMessage6 : public DeltaMessage {
	PlayerObject* play;

public:
	PlayerObjectDeltaMessage6(PlayerObject* pl);

	void setAdminLevel(uint8 level);

};
