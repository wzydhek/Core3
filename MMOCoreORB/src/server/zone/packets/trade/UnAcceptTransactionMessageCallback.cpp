#include "UnAcceptTransactionMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

UnAcceptTransactionMessageCallback::UnAcceptTransactionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void UnAcceptTransactionMessageCallback::parse(Message* message) {
}

void UnAcceptTransactionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
	playerManager->handleUnAcceptTransactionMessage(player);
}