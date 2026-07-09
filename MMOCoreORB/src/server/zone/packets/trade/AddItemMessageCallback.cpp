#include "AddItemMessageCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

AddItemMessageCallback::AddItemMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), id(0) {
}

void AddItemMessageCallback::parse(Message* message) {
	id = message->parseLong();
}

void AddItemMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	if (id == 0)
		return;

	auto zoneServer = server->getZoneServer();

	if (zoneServer == nullptr)
		return;

	auto playerMan = zoneServer->getPlayerManager();

	if (playerMan == nullptr)
		return;

	Locker lock(player);

	playerMan->handleAddItemToTradeWindow(player, id);
}