/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectMessage9 : public BaseLineMessage {
public:
	PlayerObjectMessage9(PlayerObjectImplementation* play);
};
