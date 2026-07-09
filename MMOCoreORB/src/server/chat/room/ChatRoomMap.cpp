#include "ChatRoomMap.h"
#include "server/zone/objects/creature/CreatureObject.h"

ChatRoomMap::ChatRoomMap(int initsize) : rooms(initsize) {
}

ChatRoomMap::ChatRoomMap(const ChatRoomMap& c) : Object(), rooms(c.rooms) {
}

void ChatRoomMap::put(uint32 key, ChatRoom* room) {
	rooms.put(key, room);
}

Reference<ChatRoom*> ChatRoomMap::get(uint32 key) {
	return rooms.get(key);
}

void ChatRoomMap::remove(uint32 key) {
	rooms.remove(key);
}

void ChatRoomMap::removeAll() {
	rooms.removeAll();
}

HashTableIterator<uint32, ManagedReference<ChatRoom*>> ChatRoomMap::iterator() {
	return rooms.iterator();
}