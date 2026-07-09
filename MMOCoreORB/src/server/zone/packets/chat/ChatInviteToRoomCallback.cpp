#include "ChatInviteToRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatInviteToRoomCallback::ChatInviteToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	inviteeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatInviteToRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);	  // Game name
	message->parseAscii(unused);	  // Galaxy name
	message->parseAscii(inviteeName); // Player invited
	message->parseAscii(roomPath);	  // Path to room
	requestID = message->parseInt();  // Request ID
}

void ChatInviteToRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatInvitePlayer(player, inviteeName, roomPath, requestID);
}