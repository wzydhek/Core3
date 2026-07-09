#include "CreateAuctionMessageCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/auction/AuctionManager.h"

CreateAuctionMessageCallback::CreateAuctionMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), objectID(0), vendorID(0), price(0), duration(0), premium(0) {
}

void CreateAuctionMessageCallback::parse(Message* message) {
	objectID = message->parseLong(); // object for sale
	vendorID = message->parseLong(); // vendor

	price = message->parseInt();	// Sale price
	duration = message->parseInt(); // How long to sell for in minutes

	message->parseUnicode(description);

	premium = message->parseByte();
}

void CreateAuctionMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<TangibleObject*> vendor = server->getZoneServer()->getObject(vendorID).castTo<TangibleObject*>();

	if (vendor == nullptr)
		return;

	if (!vendor->isBazaarTerminal() && !vendor->isVendor())
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->addSaleItem(player, objectID, vendor, description, price, duration, true, premium);
}