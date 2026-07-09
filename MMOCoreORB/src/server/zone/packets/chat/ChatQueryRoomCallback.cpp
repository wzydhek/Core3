#include "ChatQueryRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatQueryRoomCallback::ChatQueryRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	requestID = -1;
	roomPath = "";
}

void ChatQueryRoomCallback::parse(Message* message) {
	requestID = message->parseInt();
	message->parseAscii(roomPath);
}

void ChatQueryRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatQueryRoom(player, roomPath, requestID);
}