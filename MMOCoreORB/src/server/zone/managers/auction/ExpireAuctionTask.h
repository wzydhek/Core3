/*
 * ExpireAuctionTask.h
 *
 *  Created on: 6/22/2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/managers/auction/AuctionManager.h"

class ExpireAuctionTask : public Task {
	ManagedWeakReference<AuctionManager*> auctionManager;
	ManagedWeakReference<AuctionItem*> item;

public:
	ExpireAuctionTask(AuctionManager* manager, AuctionItem* it);

	void run();
};
