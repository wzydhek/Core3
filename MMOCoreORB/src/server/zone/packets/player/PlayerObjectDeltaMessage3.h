/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectDeltaMessage3 : public DeltaMessage {
	PlayerObject* ghost;

public:
	PlayerObjectDeltaMessage3(PlayerObject* pl);

	void updatePlayerBitmasks();

	void updateProfileBitmasks();

	void setCurrentTitle(const String& pTitle);

	void setBirthDate();

	void setTotalPlayTime();
};
