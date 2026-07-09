#include "GiveMoneyMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

GiveMoneyMessageCallback::GiveMoneyMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), money(0) {
}

void GiveMoneyMessageCallback::parse(Message* message) {
	money = message->parseInt();
}

void GiveMoneyMessageCallback::run() {
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

	playerMan->handleGiveMoneyMessage(player, money);
}