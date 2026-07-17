/*
 * CheckAuctionsTask.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/managers/auction/AuctionManager.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class CheckAuctionsTask : public Task {
	ManagedWeakReference<AuctionManager*> auctionManager;

public:
	CheckAuctionsTask(AuctionManager* manager);

	void run();
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
