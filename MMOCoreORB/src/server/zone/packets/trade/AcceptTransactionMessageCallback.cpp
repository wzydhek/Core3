#include "AcceptTransactionMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

AcceptTransactionMessageCallback::AcceptTransactionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void AcceptTransactionMessageCallback::parse(Message* message) {
}

void AcceptTransactionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
	playerManager->handleAcceptTransactionMessage(player);
}