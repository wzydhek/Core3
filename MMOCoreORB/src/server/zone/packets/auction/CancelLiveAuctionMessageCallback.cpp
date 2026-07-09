#include "CancelLiveAuctionMessageCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

CancelLiveAuctionMessageCallback::CancelLiveAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectid(0) {
}

void CancelLiveAuctionMessageCallback::parse(Message* message) {
	objectid = message->parseLong(); // object being canceled
}

void CancelLiveAuctionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->cancelItem(player, objectid);
}