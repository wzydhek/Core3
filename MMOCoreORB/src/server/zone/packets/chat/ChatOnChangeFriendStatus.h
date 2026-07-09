/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnChangeFriendStatus : public BaseMessage {
public:
	ChatOnChangeFriendStatus(uint64 oid, const String& name, const String& server, bool add);

};
