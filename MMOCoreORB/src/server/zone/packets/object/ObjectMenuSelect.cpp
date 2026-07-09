#include "ObjectMenuSelect.h"
#include "server/zone/managers/radial/RadialManager.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"

ObjectMenuSelectCallback::ObjectMenuSelectCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectID(0), radialID(0) {
}

void ObjectMenuSelectCallback::parse(Message* message) {
	objectID = message->parseLong();
	radialID = message->parseByte();
}

void ObjectMenuSelectCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player != nullptr) {
		RadialManager* radialManager = server->getZoneServer()->getRadialManager();
		radialManager->handleObjectMenuSelect(player, radialID, objectID);
	}
}