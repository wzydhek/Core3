#include "ClearClientEvent.h"
#include "server/zone/ZoneClientSession.h"

ClearClientEvent::ClearClientEvent(CreatureObject* pl, ZoneClientSession* cl) : Task() {
	player = pl;
	client = cl;
}

void ClearClientEvent::run() {
	if (player == nullptr || client == nullptr)
		return;

	Locker _locker(player);

	if (player->getClient() == client)
		player->setClient(nullptr);
}