#include "ChatAddModeratorToRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatAddModeratorToRoomCallback::ChatAddModeratorToRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	opeeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatAddModeratorToRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);	 // Game name
	message->parseAscii(unused);	 // Galaxy name
	message->parseAscii(opeeName);	 // Player to op
	message->parseAscii(roomPath);	 // Path to room
	requestID = message->parseInt(); // Request ID
}

void ChatAddModeratorToRoomCallback::run() {
	ManagedReference<CreatureObject*> oper = client->getPlayer();

	if (oper == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatAddModerator(oper, opeeName, roomPath, requestID);
}