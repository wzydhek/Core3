/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/intangible/IntangibleObjectMessage3.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectMessage3 : public IntangibleObjectMessage3 {
public:
	PlayerObjectMessage3(PlayerObject* ghost);

};
