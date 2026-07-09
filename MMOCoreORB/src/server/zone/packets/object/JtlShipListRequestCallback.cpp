#include "JtlShipListRequestCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/object/JtlShipListResponse.h"

JtlShipListRequestCallback::JtlShipListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), objectControllerMain(objectControllerCallback), terminalObjectID(0) {
}

void JtlShipListRequestCallback::parse(Message* message) {
	message->shiftOffset(4);
	terminalObjectID = message->parseLong();
}

void JtlShipListRequestCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<SceneObject*> invokedObject = server->getZoneServer()->getObject(terminalObjectID);

	if (invokedObject == nullptr)
		return;

	// This should be handled by the radial?
	if (!invokedObject->isInRange(player, 9.f)) {
		player->sendSystemMessage("You are too far out of range.");
		return;
	}

	JtlShipListResponse* resp = new JtlShipListResponse(player, invokedObject);
	player->sendMessage(resp);
}