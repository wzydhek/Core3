/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnReceiveRoomInvitation : public BaseMessage {
public:
	ChatOnReceiveRoomInvitation(const String& galaxy, const String& moderator, const String& roomPath);

};
