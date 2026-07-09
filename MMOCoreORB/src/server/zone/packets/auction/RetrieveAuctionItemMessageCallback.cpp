#include "RetrieveAuctionItemMessageCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

RetrieveAuctionItemMessageCallback::RetrieveAuctionItemMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectid(0), bazaarid(0) {
}

void RetrieveAuctionItemMessageCallback::parse(Message* message) {
	objectid = message->parseLong(); // object for sale
	bazaarid = message->parseLong(); // bazaar
}

void RetrieveAuctionItemMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->retrieveItem(player, objectid, bazaarid);
}