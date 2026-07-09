#include "GetAuctionDetailsCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

GetAuctionDetailsCallback::GetAuctionDetailsCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectid(0) {
}

void GetAuctionDetailsCallback::parse(Message* message) {
	objectid = message->parseLong();
}

void GetAuctionDetailsCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->getItemAttributes(player, objectid);
}