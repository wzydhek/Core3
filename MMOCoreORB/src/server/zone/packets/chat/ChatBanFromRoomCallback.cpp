#include "ChatBanFromRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatBanFromRoomCallback::ChatBanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	baneeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatBanFromRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);	 // Game name
	message->parseAscii(unused);	 // Galaxy name
	message->parseAscii(baneeName);	 // Player to ban
	message->parseAscii(roomPath);	 // Path to room
	requestID = message->parseInt(); // Request ID
}

void ChatBanFromRoomCallback::run() {
	ManagedReference<CreatureObject*> banner = client->getPlayer();

	if (banner == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatBanPlayer(banner, baneeName, roomPath, requestID);
}