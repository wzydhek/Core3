#include "AuctionQueryHeadersMessageCallback.h"
#include "server/zone/managers/auction/AuctionManager.h"
#include "server/zone/ZoneServer.h"

AuctionQueryHeadersMessageCallback::AuctionQueryHeadersMessageCallback(ZoneClientSession* client, ZoneProcessServer* server)
	: MessageCallback(client, server), locationType(0), counter(0), searchType(0), itemCategory(0), unk1(0), unk2(0), minPrice(0), maxPrice(0), includeEntranceFee(0), vendorID(0), isVendor(0), offset(0) {
}

void AuctionQueryHeadersMessageCallback::parse(Message* message) {
	locationType = message->parseInt();
	counter = message->parseInt();
	searchType = message->parseInt();
	itemCategory = message->parseInt(); // Bitmask

	unk1 = message->parseInt();
	message->parseUnicode(filterText);
	unk2 = message->parseInt();
	minPrice = message->parseInt();
	maxPrice = message->parseInt();
	includeEntranceFee = message->parseByte();

	vendorID = message->parseLong();
	isVendor = message->parseByte(); // Becomes one when using a vendor.
	offset = message->parseShort();
}

void AuctionQueryHeadersMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Locker locker(player);

	AuctionManager* auctionManager = server->getZoneServer()->getAuctionManager();

	if (auctionManager != nullptr)
		auctionManager->getData(player, locationType, vendorID, searchType, itemCategory, filterText, minPrice, maxPrice, includeEntranceFee, counter, offset);
}