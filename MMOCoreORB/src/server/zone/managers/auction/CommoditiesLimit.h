/*
 * CommoditiesLimit.h
 *
 *  Created on: Aug 4, 2012
 *      Author: kyle
 */

#pragma once

class CommoditiesLimit : public VectorMap<uint64, Vector<ManagedWeakReference<AuctionItem*> > >, public ReadWriteLock {

};
