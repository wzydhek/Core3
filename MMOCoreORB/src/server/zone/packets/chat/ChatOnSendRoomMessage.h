/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnSendRoomMessage : public BaseMessage {
public:
	ChatOnSendRoomMessage(uint32 seq, int error = 0) : BaseMessage() {
		insertShort(0x03);
		insertInt(0xE7B61633);  // Opcode
		insertInt(error);
		insertInt(seq);
	}

};
