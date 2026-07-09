#include "ChatUnbanFromRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatUnbanFromRoomCallback::ChatUnbanFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	unbaneeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatUnbanFromRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);	  // Game name
	message->parseAscii(unused);	  // Galaxy name
	message->parseAscii(unbaneeName); // Player unbanned
	message->parseAscii(roomPath);	  // Path to room
	requestID = message->parseInt();  // Request ID
}

void ChatUnbanFromRoomCallback::run() {
	ManagedReference<CreatureObject*> unbanner = client->getPlayer();

	if (unbanner == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatUnbanPlayer(unbanner, unbaneeName, roomPath, requestID);
}