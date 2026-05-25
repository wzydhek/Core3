/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class PlayerMoneyResponseMessage : public BaseMessage {
public:
    PlayerMoneyResponseMessage(CreatureObject* creo) : BaseMessage(20) {
		insertShort(0x03);
		insertInt(0x367E737E);  // CRC
  
		insertInt(creo->getBankCredits());
		insertInt(creo->getCashCredits());
	}
	
};
