#include "CommoditiesItemTypeListResponse.h"

CommoditiesItemTypeListResponse::CommoditiesItemTypeListResponse() : BaseMessage() {
	insertShort(0x02);
	insertInt(0xD4E937FC); // CRC

	insertAscii("Core3.0");
	insertInt(0);

	setCompression(true);
}

CommoditiesItemTypeListRequestCallback::CommoditiesItemTypeListRequestCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void CommoditiesItemTypeListRequestCallback::parse(Message* message) {
	message->parseAscii(request);
}

void CommoditiesItemTypeListRequestCallback::run() {
	CommoditiesItemTypeListResponse* citlr = new CommoditiesItemTypeListResponse();
	client->sendMessage(citlr);
}