#include "ChatEnterRoomByIdCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatEnterRoomByIdCallback::ChatEnterRoomByIdCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), requestID(0), roomID(0) {
}

void ChatEnterRoomByIdCallback::parse(Message* message) {
	requestID = message->parseInt();
	roomID = message->parseInt();
}

void ChatEnterRoomByIdCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatEnterRoomById(player, roomID, requestID);
}