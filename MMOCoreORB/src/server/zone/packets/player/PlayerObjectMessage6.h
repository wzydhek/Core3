/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/player/PlayerObject.h"

class PlayerObjectMessage6 : public BaseLineMessage {
public:
	PlayerObjectMessage6(PlayerObject* play)
			: BaseLineMessage(play->getObjectID(), 0x504C4159, 6, 0x03) {

		insertInt(0);

		uint8 privFlag = play->getPriviledgeFlag();

		insertByte(privFlag);  //Developer/CSR Flag

		setSize();
	}

};
