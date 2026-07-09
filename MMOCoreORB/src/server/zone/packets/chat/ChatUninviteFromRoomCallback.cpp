#include "ChatUninviteFromRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatUninviteFromRoomCallback::ChatUninviteFromRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	uninviteeName = "";
	roomPath = "";
	requestID = 0;
}

void ChatUninviteFromRoomCallback::parse(Message* message) {
	String unused;

	message->parseAscii(unused);		// Game name
	message->parseAscii(unused);		// Galaxy name
	message->parseAscii(uninviteeName); // Player uninvited
	message->parseAscii(roomPath);		// Path to room
	requestID = message->parseInt();	// requestID
}

void ChatUninviteFromRoomCallback::run() {
	ManagedReference<CreatureObject*> uninviter = client->getPlayer();

	if (uninviter == nullptr)
		return;

	ManagedReference<ChatManager*> chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatUninvitePlayer(uninviter, uninviteeName, roomPath, requestID);
}