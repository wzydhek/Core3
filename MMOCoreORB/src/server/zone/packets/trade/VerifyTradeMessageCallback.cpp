#include "VerifyTradeMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

VerifyTradeMessageCallback::VerifyTradeMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void VerifyTradeMessageCallback::parse(Message* message) {
}

void VerifyTradeMessageCallback::run() {
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

	playerMan->handleVerifyTradeMessage(player);
}