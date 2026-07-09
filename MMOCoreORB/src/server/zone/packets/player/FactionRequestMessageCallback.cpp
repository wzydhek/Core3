#include "FactionRequestMessageCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "FactionResponseMessage.h"

FactionRequestMessageCallback::FactionRequestMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void FactionRequestMessageCallback::parse(Message* message) {
}

void FactionRequestMessageCallback::run() {
	ManagedReference<CreatureObject*> object = client->getPlayer();

	if (object == nullptr)
		return;

	Locker _locker(object);

	ManagedReference<PlayerObject*> ghost = object->getPlayerObject();

	FactionResponseMessage* frm = new FactionResponseMessage(ghost->getFactionStandingList());
	object->sendMessage(frm);
}