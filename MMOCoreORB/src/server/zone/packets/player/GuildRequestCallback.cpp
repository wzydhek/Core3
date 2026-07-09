#include "GuildRequestCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "GuildResponseMessage.h"

GuildRequestCallback::GuildRequestCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectID(0) {
}

void GuildRequestCallback::parse(Message* message) {
	objectID = message->parseLong();
}

void GuildRequestCallback::run() {
	ManagedReference<SceneObject*> obj = server->getZoneServer()->getObject(objectID);

	if (obj == nullptr || !obj->isCreatureObject())
		return;

	CreatureObject* creature = cast<CreatureObject*>(obj.get());

	GuildResponseMessage* msg = new GuildResponseMessage(creature);
	client->sendMessage(msg);
}