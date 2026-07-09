#include "AuctionSearchTask.h"

AuctionSearchTask::AuctionSearchTask(AuctionManager* manager, CreatureObject* play, SceneObject* uVendor, const String& plnt, const String& reg, SceneObject* vend, int scr, uint32 cat, const UnicodeString& filter, int minP, int maxP, bool entFee, int counter, int off) {
	auctionManager = manager;
	player = play;
	vendorInUse = uVendor;
	vendor = vend;
	planet = plnt;
	region = reg;
	screen = scr;
	category = cat;
	minPrice = minP;
	maxPrice = maxP;
	clientCounter = counter;
	offset = off;
	filterText = filter;
	includeEntranceFee = entFee;

	setCustomTaskQueue("AuctionSearch");
}

void AuctionSearchTask::run() {
	ManagedReference<AuctionManager*> strongRef = auctionManager.get();

	if (strongRef == nullptr)
		return;

	ManagedReference<CreatureObject*> strongPlayer = player.get();

	if (strongPlayer == nullptr)
		return;

	ManagedReference<SceneObject*> strongVendorInUse = vendorInUse.get();

	if (strongVendorInUse == nullptr)
		return;

	ManagedReference<SceneObject*> strongVendor = vendor.get();

	Locker locker(strongPlayer);

	strongRef->getAuctionData(strongPlayer, strongVendorInUse, planet, region, strongVendor, screen, category, filterText, minPrice, maxPrice, includeEntranceFee, clientCounter, offset);
}