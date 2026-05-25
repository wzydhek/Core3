/*
 * DogfightTauntPlayerMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

class DogfightTauntPlayerMessage : public BaseMessage {
public:
	DogfightTauntPlayerMessage() : BaseMessage() {
		insertShort(0x09);
		insertInt(0xCA2A548B);  // CRC

		insertLong(0);
		insertInt(0);


   }

};
