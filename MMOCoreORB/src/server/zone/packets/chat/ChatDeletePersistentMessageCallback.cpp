#include "ChatDeletePersistentMessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

ChatDeletePersistentMessageCallback::ChatDeletePersistentMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), mailid(0) {
}

void ChatDeletePersistentMessageCallback::parse(Message* message) {
	mailid = message->parseInt();
}

void ChatDeletePersistentMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager != nullptr)
		chatManager->deletePersistentMessage(player, mailid);
}