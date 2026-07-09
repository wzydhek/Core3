#include "ChatSendToRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"
#include "server/zone/ZoneServer.h"

ChatSendToRoomCallback::ChatSendToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), roomID(0), counter(0) {
}

void ChatSendToRoomCallback::parse(Message* message) {
	message->parseUnicode(chatMessage);

	message->shiftOffset(4); //?

	roomID = message->parseInt();

	counter = message->parseInt();
}

void ChatSendToRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getZoneServer()->getChatManager();

	if (chatManager != nullptr)
		chatManager->handleChatRoomMessage(player, chatMessage, roomID, counter);
}