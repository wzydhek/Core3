#include "BidAuctionMessageCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

BidAuctionMessageCallback::BidAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectid(0), price1(0), price2(0) {
	setCustomTaskQueue("slowQueue");
}

void BidAuctionMessageCallback::parse(Message* message) {
	objectid = message->parseLong();
	price1 = message->parseInt();
	price2 = message->parseInt();
}

void BidAuctionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr) {
		Locker clocker(auctionManager, player);

		auctionManager->buyItem(player, objectid, price1, price2);
	}
}