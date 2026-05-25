/*
 * AuctionEventsMap.h
 *
 *  Created on: 09/08/2012
 *      Author: victor
 */

#pragma once

class AuctionEventsMap : public VectorMap<uint64, Reference<Task*> >, public Mutex {

};
