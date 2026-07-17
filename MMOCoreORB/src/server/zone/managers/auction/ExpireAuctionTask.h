/*
 * ExpireAuctionTask.h
 *
 *  Created on: 6/22/2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/managers/auction/AuctionManager.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class ExpireAuctionTask : public Task {
	ManagedWeakReference<AuctionManager*> auctionManager;
	ManagedWeakReference<AuctionItem*> item;

public:
	ExpireAuctionTask(AuctionManager* manager, AuctionItem* it);

	void run();
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
