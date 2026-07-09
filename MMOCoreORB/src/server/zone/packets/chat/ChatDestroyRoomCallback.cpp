#include "ChatDestroyRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatDestroyRoomCallback::ChatDestroyRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	roomID = 0;
	requestID = 0;
}

void ChatDestroyRoomCallback::parse(Message* message) {
	roomID = message->parseInt();
	requestID = message->parseInt();
}

void ChatDestroyRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatDestroyRoom(player, roomID, requestID);
}