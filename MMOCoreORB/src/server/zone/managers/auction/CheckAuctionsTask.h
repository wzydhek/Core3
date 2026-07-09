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
	CheckAuctionsTask(AuctionManager* manager);

	void run();
};
