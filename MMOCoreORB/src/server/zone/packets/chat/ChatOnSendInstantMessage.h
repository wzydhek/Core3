/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnSendInstantMessage : public BaseMessage {
public:
	ChatOnSendInstantMessage(uint32 seq, int result = 0); 
	
};
