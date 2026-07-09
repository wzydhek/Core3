/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectMessage6 : public BaseLineMessage {
public:
	PlayerObjectMessage6(PlayerObject* play);

};
