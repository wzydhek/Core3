/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "server/chat/room/ChatRoom.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatRoomList : public BaseMessage {
	int channelCounter;

public:
	ChatRoomList();

	void addChannel(ChatRoom* channel);

	void insertChannelListCount();

};

class ChatRequestRoomListCallback : public MessageCallback {
public:
	ChatRequestRoomListCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();
};

}
}
}
}

using namespace server::zone::packets::chat;
