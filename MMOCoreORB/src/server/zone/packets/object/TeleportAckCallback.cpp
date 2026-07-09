#include "TeleportAckCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"

TeleportAckCallback::TeleportAckCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), movementCounter(0), objectControllerMain(objectControllerCallback) {
}

void TeleportAckCallback::parse(Message* message) {
	movementCounter = message->parseInt();
}

void TeleportAckCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr) {
		return;
	}

	auto ghost = player->getPlayerObject();

	if (ghost == nullptr) {
		return;
	}

	ghost->setTeleporting(false);
}