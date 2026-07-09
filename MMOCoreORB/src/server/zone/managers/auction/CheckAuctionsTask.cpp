#include "CheckAuctionsTask.h"
#include "server/zone/ZoneServer.h"

CheckAuctionsTask::CheckAuctionsTask(AuctionManager* manager) {
	auctionManager = manager;

	setCustomTaskQueue("slowQueue");
}

void CheckAuctionsTask::run() {
	ManagedReference<AuctionManager*> strongRef = auctionManager.get();

	if (strongRef == nullptr)
		return;

	ZoneServer* server = strongRef->getZoneServer();

	if (server == nullptr || server->isServerShuttingDown())
		return;

	strongRef->checkAuctions();
	strongRef->checkVendorItems();
}