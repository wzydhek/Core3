/*
 * CheckAuctionsTask.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/managers/auction/AuctionManager.h"

class CheckAuctionsTask : public Task {
	ManagedWeakReference<AuctionManager*> auctionManager;

public:
	CheckAuctionsTask(AuctionManager* manager) {
		auctionManager = manager;

		setCustomTaskQueue("slowQueue");
	}

	void run() {
		ManagedReference<AuctionManager*> strongRef = auctionManager.get();

		if (strongRef == nullptr)
			return;

		ZoneServer* server = strongRef->getZoneServer();

		if (server == nullptr || server->isServerShuttingDown())
			return;

		strongRef->checkAuctions();
		strongRef->checkVendorItems();
	}
};
