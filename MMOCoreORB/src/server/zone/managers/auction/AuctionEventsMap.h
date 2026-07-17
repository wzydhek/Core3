/*
 * AuctionEventsMap.h
 *
 *  Created on: 09/08/2012
 *      Author: victor
 */

#pragma once

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionEventsMap : public VectorMap<uint64, Reference<Task*>>, public Mutex {};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
