#include "ExpireAuctionTask.h"

ExpireAuctionTask::ExpireAuctionTask(AuctionManager* manager, AuctionItem* it) {
	auctionManager = manager;
	item = it;
}

void ExpireAuctionTask::run() {
	ManagedReference<AuctionManager*> strongRef = auctionManager.get();
	ManagedReference<AuctionItem*> strongRefItem = item.get();

	if (strongRef == nullptr || strongRefItem == nullptr)
		return;

	strongRef->expireAuction(strongRefItem);
}