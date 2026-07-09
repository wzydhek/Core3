#include "ChatRequestPersistentMessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatRequestPersistentMessageCallback::ChatRequestPersistentMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), mailid(0) {
}

void ChatRequestPersistentMessageCallback::parse(Message* message) {
	message->shiftOffset(4); // skip spacer/unk
	mailid = message->parseInt();
}

void ChatRequestPersistentMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();

	if (chatManager != nullptr)
		chatManager->handleRequestPersistentMsg(player, mailid);
}