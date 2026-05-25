/*
 * unkZone.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

 // test

#include "engine/service/proto/BaseMessage.h"

class unkZone : public BaseMessage {
public:
	unkZone() : BaseMessage() {
		insertShort(0x02);
		insertInt(0x58C07F21);
		insertByte(0x44);
		insertByte(0x05);
		insertByte(0);
		insertByte(0);

	}

};
