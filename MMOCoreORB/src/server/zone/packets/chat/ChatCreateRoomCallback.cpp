#include "ChatCreateRoomCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatCreateRoomCallback::ChatCreateRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	moderationFlag = 0;
	permissionFlag = 0;
	roomPath = "";
	roomTitle = "";
	requestID = 0;
	unknown = 0;

	setCustomTaskQueue("slowQueue");
}

void ChatCreateRoomCallback::parse(Message* message) {
	permissionFlag = message->parseByte();
	moderationFlag = message->parseByte();
	unknown = message->parseShort(); // not used, always 0.
	message->parseAscii(roomPath);
	message->parseAscii(roomTitle);
	requestID = message->parseInt();
}

void ChatCreateRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->handleChatCreateRoom(player, permissionFlag, moderationFlag, roomPath, roomTitle, requestID);
}