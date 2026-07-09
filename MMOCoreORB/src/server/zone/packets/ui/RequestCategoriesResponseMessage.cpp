#include "RequestCategoriesResponseMessage.h"
#include "server/zone/managers/holocron/HolocronManager.h"

RequestCategoriesResponseMessage::RequestCategoriesResponseMessage(SortedVector<BugCategory>* categories) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x61148FD4); // CRC

	insertInt(0); //??
	insertInt(categories->size());

	for (int i = 0; i < categories->size(); ++i) {
		BugCategory* category = &categories->get(i);

		if (category == nullptr)
			continue;

		category->insertToMessage(this);
	}

	setCompression(true);
}

RequestCategoriesMessageCallback::RequestCategoriesMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void RequestCategoriesMessageCallback::parse(Message* message) {
	message->parseAscii(language);
}

void RequestCategoriesMessageCallback::run() {
	HolocronManager* holocronManager = server->getHolocronManager();
	holocronManager->sendRequestCategoriesResponseTo(client);
}