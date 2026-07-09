#include "ChatLeaveRoomCallback.h"
#include "server/chat/ChatManager.h"
#include "server/zone/objects/creature/CreatureObject.h"

ChatLeaveRoomCallback::ChatLeaveRoomCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
	roomPath = "";
	leavingName = "";
}

void ChatLeaveRoomCallback::parse(Message* message) {
	String unused = "";
	message->parseAscii(unused);	  // Game
	message->parseAscii(unused);	  // Galaxy
	message->parseAscii(leavingName); // Player Name
	message->parseAscii(roomPath);	  // Full room path
}

void ChatLeaveRoomCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager == nullptr)
		return;

	String senderName = player->getFirstName().toLowerCase();

	if (senderName != leavingName.toLowerCase()) { // One player is kicking another from a room.
		chatManager->handleChatKickPlayer(player, leavingName, roomPath);
	} else { // Player is just trying to leave a room (or kicked himself).
		Locker locker(player);
		chatManager->handleChatLeaveRoom(player, roomPath);
	}
}