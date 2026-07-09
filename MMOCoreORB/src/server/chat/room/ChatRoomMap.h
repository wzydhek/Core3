/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/chat/room/ChatRoom.h"

namespace server {
namespace chat {
namespace room {

class ChatRoomMap : public Object {
	HashTable<uint32, ManagedReference<ChatRoom*> > rooms;

public:
	ChatRoomMap(int initsize);

	ChatRoomMap(const ChatRoomMap& c);

	void put(uint32 key, ChatRoom* room);

	Reference<ChatRoom*> get(uint32 key);

	void remove(uint32 key);

	void removeAll();

	HashTableIterator<uint32, ManagedReference<ChatRoom*>> iterator();
};


}
}
}

using namespace server::chat::room;
