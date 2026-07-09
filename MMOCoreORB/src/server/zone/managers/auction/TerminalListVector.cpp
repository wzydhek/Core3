#include "TerminalListVector.h"

TerminalItemList::TerminalItemList() {
	searchable = false;
}

TerminalItemList::TerminalItemList(const TerminalItemList& list) : SortedVector<ManagedReference<AuctionItem*>>(list), ReadWriteLock() {
	searchable = list.searchable;
}

TerminalItemList& TerminalItemList::operator=(const TerminalItemList& list) {
	if (this == &list)
		return *this;

	searchable = list.searchable;

	return *this;
}

void TerminalItemList::setSearchable(bool value) {
	searchable = value;
}

bool TerminalItemList::isSearchable() {
	return searchable == true;
}

int TerminalItemList::put(const ManagedReference<AuctionItem*>& o) {
	Locker locker(this);

	return SortedVector<ManagedReference<AuctionItem*>>::put(o);
}

bool TerminalItemList::drop(const ManagedReference<AuctionItem*>& o) {
	Locker locker(this);

	return SortedVector<ManagedReference<AuctionItem*>>::drop(o);
}