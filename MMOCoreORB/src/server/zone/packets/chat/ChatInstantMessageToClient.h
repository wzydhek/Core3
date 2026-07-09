/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatInstantMessageToClient : public BaseMessage {
public:
	ChatInstantMessageToClient(const String& game, const String& galaxy, const String& name, const UnicodeString& message);
	
};
