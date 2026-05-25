/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectDeltaMessage6 : public DeltaMessage {
	PlayerObject* play;

public:
	PlayerObjectDeltaMessage6(PlayerObject* pl)
			: DeltaMessage(pl->getObjectID(), 0x504C4159, 6) {
		play = pl;
	}

	void setAdminLevel(uint8 level) {
		startUpdate(1);
		insertByte(level);
	}

};
