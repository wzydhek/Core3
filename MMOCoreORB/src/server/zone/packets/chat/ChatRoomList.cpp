#include "ChatRoomList.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatRoomList::ChatRoomList() : BaseMessage() {
	insertShort(0x02);
	insertInt(0x70DEB197); // Opcode

	insertInt(0); // List Count

	channelCounter = 0;

	setCompression(true);
}

void ChatRoomList::addChannel(ChatRoom* channel) {
	channelCounter++;

	insertInt(channel->getRoomID());

	if (channel->isPublic())
		insertInt(0);
	else
		insertInt(1);

	if (!channel->isModerated())
		insertByte(0);
	else
		insertByte(1);

	insertAscii(channel->getFullPath());

	insertAscii("SWG");
	insertAscii(channel->getGalaxyName());
	insertAscii(channel->getOwnerName());

	// This struct is a ChatAvatarId
	insertAscii("SWG");
	insertAscii(channel->getGalaxyName());
	insertAscii(channel->getCreator());

	insertUnicode(channel->getTitle());

	insertInt(0); // Moderator & Player lists not needed in this packet.
	insertInt(0);
}

void ChatRoomList::insertChannelListCount() {
	insertInt(10, channelCounter);
}

ChatRequestRoomListCallback::ChatRequestRoomListCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void ChatRequestRoomListCallback::parse(Message* message) {
}

void ChatRequestRoomListCallback::run() {
	ChatManager* chatManager = server->getChatManager();

	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player != nullptr && chatManager != nullptr)
		chatManager->sendRoomList(player);
}