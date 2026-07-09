#include "CreateTicketMessageCallback.h"
#include "conf/ConfigManager.h"
#include "server/zone/managers/holocron/HolocronManager.h"

CreateTicketMessageCallback::CreateTicketMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), categoryId(0), subCategoryId(0) {
}

void CreateTicketMessageCallback::parse(Message* message) {
	if (!ConfigManager::instance()->getBool("Core3.AccountManager.HolocronTicketsEnabled", false)) {
		return;
	}

	message->parseAscii(playerName);
	categoryId = message->parseInt();
	subCategoryId = message->parseInt();

	message->parseUnicode(ticketBody);
}

void CreateTicketMessageCallback::run() {
	if (!ConfigManager::instance()->getBool("Core3.AccountManager.HolocronTicketsEnabled", false)) {
		return;
	}

	HolocronManager* holocronManager = server->getHolocronManager();
	holocronManager->submitTicket(client, ticketBody);
}