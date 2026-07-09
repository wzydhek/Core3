/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

//Mail

#include "engine/service/proto/BaseMessage.h"

class ChatOnSendPersistentMessage : public BaseMessage {
public:
	ChatOnSendPersistentMessage(uint32 seq, int returnCode);
	
};
