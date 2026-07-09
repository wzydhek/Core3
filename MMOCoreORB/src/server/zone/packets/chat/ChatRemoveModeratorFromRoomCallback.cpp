#include "ChatRemoveModeratorFromRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatRemoveModeratorFromRoomCallback::ChatRemoveModeratorFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	deopeeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatRemoveModeratorFromRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);	 // Game name
	message->parseAscii(unused);	 // Galaxy name
	message->parseAscii(deopeeName); // Player to deop
	message->parseAscii(roomPath);	 // Path to room
	requestID = message->parseInt(); // requestID
}

void ChatRemoveModeratorFromRoomCallback::run() {
	ManagedReference<CreatureObject*> deoper = client->getPlayer();

	if (deoper == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatRemoveModerator(deoper, deopeeName, roomPath, requestID);
}