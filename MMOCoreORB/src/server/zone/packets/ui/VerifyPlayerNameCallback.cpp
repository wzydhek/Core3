#include "VerifyPlayerNameCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/packets/ui/VerifyPlayerNameResponseMessage.h"

VerifyPlayerNameCallback::VerifyPlayerNameCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), playerID(0) {
}

void VerifyPlayerNameCallback::parse(Message* message) {
	message->parseUnicode(name);
	playerID = message->parseLong();
}

void VerifyPlayerNameCallback::run() {
	ManagedReference<CreatureObject*> playerCreature = client->getPlayer();

	if (playerCreature == nullptr)
		return;

	ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();
	bool success = playerManager->existsName(name.toString());

	VerifyPlayerNameResponseMessage* vpnrm = new VerifyPlayerNameResponseMessage(success);
	playerCreature->sendMessage(vpnrm);
}