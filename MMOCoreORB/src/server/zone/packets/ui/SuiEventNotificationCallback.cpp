#include "SuiEventNotificationCallback.h"
#include "server/zone/managers/sui/SuiManager.h"

SuiEventNotificationCallback::SuiEventNotificationCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), pageId(0), eventIndex(0), listSize1(0), listSize2(0) {
}

void SuiEventNotificationCallback::parse(Message* message) {
	pageId = message->parseInt();

	eventIndex = message->parseInt();
	listSize1 = message->parseInt();
	listSize2 = message->parseInt();

	for (int i = 0; i < listSize1; ++i) {
		UnicodeString arg;
		message->parseUnicode(arg);
		arguments.add(arg);
	}
}

void SuiEventNotificationCallback::run() {
	ManagedReference<CreatureObject*> playerCreature = client->getPlayer();

	if (playerCreature == nullptr)
		return;

	server->getSuiManager()->handleSuiEventNotification(pageId, playerCreature, eventIndex, &arguments);
}