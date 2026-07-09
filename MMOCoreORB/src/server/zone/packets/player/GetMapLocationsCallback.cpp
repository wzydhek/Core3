#include "GetMapLocationsCallback.h"
#include "server/zone/Zone.h"

GetMapLocationsCallback::GetMapLocationsCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void GetMapLocationsCallback::parse(Message* message) {
	message->parseAscii(zoneName);
}

void GetMapLocationsCallback::run() {
	ManagedReference<CreatureObject*> object = client->getPlayer();

	if (object == nullptr)
		return;

	Locker _locker(object);

	Zone* zone = server->getZoneServer()->getZone(zoneName);

	if (zone != nullptr && !zone->isSpaceZone())
		zone->sendMapLocationsTo(object);
}