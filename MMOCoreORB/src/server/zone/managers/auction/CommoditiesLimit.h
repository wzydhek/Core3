/*
 * CommoditiesLimit.h
 *
 *  Created on: Aug 4, 2012
 *      Author: kyle
 */

#pragma once

namespace server {
namespace zone {
namespace managers {
namespace auction {

class CommoditiesLimit : public VectorMap<uint64, Vector<ManagedWeakReference<AuctionItem*> > >, public ReadWriteLock {

};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
