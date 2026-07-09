#include "PlayerMoneyRequest.h"
#include "PlayerMoneyResponseMessage.h"

PlayerMoneyRequestMessageCallback::PlayerMoneyRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void PlayerMoneyRequestMessageCallback::parse(Message* message) {
}

void PlayerMoneyRequestMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	PlayerMoneyResponseMessage* reply = new PlayerMoneyResponseMessage(player);
	client->sendMessage(reply);
}