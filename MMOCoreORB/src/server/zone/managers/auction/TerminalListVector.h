/*
 * TerminalListVector.h
 *
 *  Created on: Jul 4, 2012
 *      Author: kyle
 */

#pragma once

#include "system/util/SortedVector.h"
#include "server/zone/objects/auction/AuctionItem.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class TerminalItemList : public SortedVector<ManagedReference<AuctionItem*> >, public ReadWriteLock {
protected:
	bool searchable;

public:
	TerminalItemList();

	TerminalItemList(const TerminalItemList& list);

	TerminalItemList& operator=(const TerminalItemList& list);

	void setSearchable(bool value);

	bool isSearchable();

	int put(const ManagedReference<AuctionItem*>& o);

	bool drop(const ManagedReference<AuctionItem*>& o);

};

class TerminalRegionList : public VectorMap<uint64, Reference<TerminalItemList*> >, public ReadWriteLock {

};

class TerminalPlanetList : public VectorMap<String, Reference<TerminalRegionList*> >, public ReadWriteLock {

};

class TerminalGalaxyList : public VectorMap<String, Reference<TerminalPlanetList*> >, public ReadWriteLock {

};

class TerminalListVector : public SortedVector<Reference<TerminalItemList*> > {

};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
