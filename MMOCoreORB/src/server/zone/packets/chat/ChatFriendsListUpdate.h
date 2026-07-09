/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatFriendsListUpdate : public BaseMessage {
public:
	ChatFriendsListUpdate(const String& name, const String& server, bool online);

};
