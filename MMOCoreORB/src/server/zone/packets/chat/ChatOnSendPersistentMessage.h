/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

//Mail

#include "engine/service/proto/BaseMessage.h"

class ChatOnSendPersistentMessage : public BaseMessage {
public:
	ChatOnSendPersistentMessage(uint32 seq, int returnCode) : BaseMessage() {
		insertShort(0x03);
		insertInt(0x94E7A7AE);  // CRC

		insertInt(returnCode);
			
		insertInt(seq);
	} 
	
};
