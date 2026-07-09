#include "AbortTradeMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

AbortTradeMessageCallback::AbortTradeMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void AbortTradeMessageCallback::parse(Message* message) {
}

void AbortTradeMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	auto zoneServer = server->getZoneServer();

	if (zoneServer == nullptr)
		return;

	auto playerMan = zoneServer->getPlayerManager();

	if (playerMan == nullptr)
		return;

	Locker lock(player);

	playerMan->handleAbortTradeMessage(player);
}