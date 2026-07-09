#include "StomachRequestMessage.h"
#include "server/zone/packets/player/PlayerObjectDeltaMessage9.h"

StomachRequestMessageCallback::StomachRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void StomachRequestMessageCallback::parse(Message* message) {
}

void StomachRequestMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Reference<PlayerObject*> playerObject = player->getPlayerObject();

	PlayerObjectDeltaMessage9* delta = new PlayerObjectDeltaMessage9(playerObject);
	delta->updateStomachFilling();
	delta->close();

	client->sendMessage(delta);
}