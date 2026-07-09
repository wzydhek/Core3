#include "CreateImmediateAuctionMessageCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

CreateImmediateAuctionMessageCallback::CreateImmediateAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectID(0), vendorID(0), price(0), duration(0), premium(0) {
}

void CreateImmediateAuctionMessageCallback::parse(Message* message) {
	objectID = message->parseLong(); // object for sale
	vendorID = message->parseLong(); // vendor

	price = message->parseInt();	// Sale price
	duration = message->parseInt(); // How long to sell for in seconds

	message->parseUnicode(description);

	premium = message->parseByte(); // Preium Sale flag
}

void CreateImmediateAuctionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<TangibleObject*> vendor = server->getZoneServer()->getObject(vendorID).castTo<TangibleObject*>();

	if (vendor == nullptr || (!vendor->isVendor() && !vendor->isBazaarTerminal()))
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->addSaleItem(player, objectID, vendor, description, price, duration, false, premium);
}