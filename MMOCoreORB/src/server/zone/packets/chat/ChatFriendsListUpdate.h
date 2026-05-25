/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatFriendsListUpdate : public BaseMessage {
public:
	ChatFriendsListUpdate(const String& name, const String& server, bool online) : BaseMessage() {

		insertShort(0x03);
		insertInt(0x6CD2FCD8);  // CRC

		insertAscii("SWG");
		insertAscii(server);
		insertAscii(name);

		insertByte(online);

	}

};
