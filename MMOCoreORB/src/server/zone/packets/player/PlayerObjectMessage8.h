/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectMessage8 : public BaseLineMessage {
public:
	PlayerObjectMessage8(PlayerObjectImplementation* play);

};
