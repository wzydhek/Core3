#include "ClientInactivityMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

ClientInactivityMessageCallback::ClientInactivityMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), flag(0) {
}

void ClientInactivityMessageCallback::parse(Message* message) {
	flag = message->parseByte();
}

void ClientInactivityMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player != nullptr) {
		StringBuffer msg;
		msg << "ClientInactivityMessage with flag " << hex << flag << " received";
		player->info(msg.toString());
	}
}