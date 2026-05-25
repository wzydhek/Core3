/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

//Mail - "You got mail"
//ChatOnConnectAvatar

#include "engine/service/proto/BaseMessage.h"

class ChatOnConnectAvatar : public BaseMessage {
public:
	ChatOnConnectAvatar() : BaseMessage() {
		insertShort(0x01);
		insertInt(0xD72FE9BE);  // CRC
	} 
	
};
