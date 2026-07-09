#include "AuctionTerminalMap.h"

AuctionTerminalMap::AuctionTerminalMap() {
	setNullValue(nullptr);
	setNoDuplicateInsertPlan();

	galaxyListing.setNoDuplicateInsertPlan();
	galaxyListing.setNullValue(nullptr);

	setLoggingName("AuctionTerminalMap");
}

bool AuctionTerminalMap::createTerminalListing(const String& planet, const String& region, SceneObject* vendor) {
	// Locker locker(this);
	// Locker glocker(&galaxyListing);

	if (vendor == nullptr) {
		warning("unable to create nullptr vendor");
		return false;
	}

	if (!galaxyListing.contains(planet) && !addPlanetListing(planet)) {
		error("Unable to create planet listing");
		return false;
	}

	Reference<TerminalPlanetList*> planetList = galaxyListing.get(planet);
	if (planetList == nullptr || (!planetList->contains(region) && !addRegionListing(planetList, region))) {
		error("unable to create region listing");
		return false;
	}

	Reference<TerminalRegionList*> targetRegion = planetList->get(region);
	Reference<TerminalRegionList*> existingRegion = getVendorRegion(vendor);

	if (!targetRegion->contains(vendor->getObjectID()) || !contains(vendor->getObjectID())) {
		Reference<TerminalItemList*> itemList = nullptr;

		if (existingRegion != nullptr) {
			itemList = existingRegion->get(vendor->getObjectID());

			existingRegion->drop(vendor->getObjectID());
		}

		if (itemList == nullptr)
			itemList = get(vendor->getObjectID());

		if (itemList == nullptr) {
			itemList = new TerminalItemList();
			itemList->setNoDuplicateInsertPlan();
		}

		targetRegion->put(vendor->getObjectID(), itemList);
		put(vendor->getObjectID(), itemList);
	}
	return true;
}

bool AuctionTerminalMap::dropTerminalListing(SceneObject* vendor) {
	if (vendor == nullptr) {
		warning("unable to drop nullptr vendor");
		return false;
	}

	// Locker locker(this);
	// Locker glocker(&galaxyListing);

	Reference<TerminalRegionList*> existingRegion = getVendorRegion(vendor);
	if (existingRegion == nullptr)
		return drop(vendor->getObjectID());

	if (existingRegion->drop(vendor->getObjectID()))
		return drop(vendor->getObjectID());

	return false;
}

bool AuctionTerminalMap::updateTerminalUID(const String& planet, const String& region, SceneObject* vendor, const String& newVuid) {
	if (!createTerminalListing(planet, region, vendor)) {
		error("unable to update terminal UID");
		return false;
	}

	Reference<TerminalItemList*> itemList = get(vendor->getObjectID());

	if (itemList == nullptr)
		return false;

	if (itemList->isEmpty())
		return true;

	// Locker locker(itemList);
	for (int i = 0; i < itemList->size(); ++i) {
		ManagedReference<AuctionItem*> item = itemList->get(i);
		if (item == nullptr)
			continue;

		Locker locker(item);
		item->setVendorUID(newVuid);
	}

	return true;
}

void AuctionTerminalMap::updateTerminalSearch(SceneObject* vendor, bool enabled) {
	if (vendor == nullptr || vendor->isBazaarTerminal())
		return;

	Reference<TerminalItemList*> itemList = get(vendor->getObjectID());

	if (itemList == nullptr)
		return;

	// Locker locker(itemList);
	itemList->setSearchable(enabled);
}

TerminalListVector AuctionTerminalMap::getTerminalData(const String& planet, const String& region, SceneObject* vendor) {
	if (planet.isEmpty())
		return getGalaxyListing();

	if (region.isEmpty())
		return getPlanetListing(planet);

	if (vendor == nullptr)
		return getRegionListing(planet, region);

	TerminalListVector terminals;

	Reference<TerminalItemList*> itemList = get(vendor->getObjectID());
	if (itemList != nullptr)
		terminals.add(itemList);

	return terminals;
}

TerminalListVector AuctionTerminalMap::getGalaxyListing() {
	TerminalListVector terminals;

	// ReadLocker rlocker(this);

	for (int i = 0; i < size(); ++i) {
		Reference<TerminalItemList*> itemList = get(i);

		if (itemList == nullptr)
			continue;

		terminals.add(itemList);
	}

	return terminals;
}

TerminalListVector AuctionTerminalMap::getPlanetListing(const String& planet) {
	TerminalListVector terminals;

	Reference<TerminalPlanetList*> planetList = galaxyListing.get(planet);

	if (planetList != nullptr)
		getPlanetListing(&terminals, planetList);

	return terminals;
}

TerminalListVector AuctionTerminalMap::getRegionListing(const String& planet, const String& region) {
	TerminalListVector terminals;

	Reference<TerminalPlanetList*> planetList = galaxyListing.get(planet);

	if (planetList != nullptr) {
		Reference<TerminalRegionList*> regionList = planetList->get(region);

		if (regionList != nullptr)
			getRegionListing(&terminals, regionList);
	}

	return terminals;
}

bool AuctionTerminalMap::addPlanetListing(const String& planet) {
	if (galaxyListing.contains(planet))
		return true;

	Reference<TerminalPlanetList*> newPlanet = new TerminalPlanetList();
	newPlanet->setNoDuplicateInsertPlan();
	newPlanet->setNullValue(nullptr);

	return (galaxyListing.put(planet, newPlanet) != -1);
}

bool AuctionTerminalMap::removePlanetListing(const String& planet) {
	if (!galaxyListing.contains(planet))
		return true;

	return galaxyListing.drop(planet);
}

bool AuctionTerminalMap::addRegionListing(TerminalPlanetList* planetList, const String& region) {
	if (planetList->contains(region))
		return true;

	Reference<TerminalRegionList*> newRegion = new TerminalRegionList();
	newRegion->setNoDuplicateInsertPlan();
	newRegion->setNullValue(nullptr);

	return (planetList->put(region, newRegion) != -1);
}

bool AuctionTerminalMap::removeRegionListing(TerminalPlanetList* planetList, const String& region) {
	if (!planetList->contains(region))
		return true;

	return planetList->drop(region);
}

/// Pre Locked
TerminalRegionList* AuctionTerminalMap::getVendorRegion(SceneObject* vendor) {
	for (int i = 0; i < galaxyListing.size(); ++i) {
		Reference<TerminalPlanetList*> planetList = galaxyListing.get(i);
		if (planetList != nullptr) {
			for (int j = 0; j < planetList->size(); ++j) {
				Reference<TerminalRegionList*> regionList = planetList->get(j);

				if (regionList != nullptr) {
					for (int k = 0; k < regionList->size(); ++k) {
						if (regionList->elementAt(k).getKey() == vendor->getObjectID()) {
							return regionList;
						}
					}
				}
			}
		}
	}
	return nullptr;
}

void AuctionTerminalMap::getPlanetListing(TerminalListVector* terminals, TerminalPlanetList* planetList) {
	if (planetList != nullptr) {
		// ReadLocker rlocker(planetList);

		for (int j = 0; j < planetList->size(); ++j) {
			Reference<TerminalRegionList*> regionList = planetList->get(j);

			if (regionList != nullptr)
				getRegionListing(terminals, regionList);
		}
	}
}

void AuctionTerminalMap::getRegionListing(TerminalListVector* terminals, TerminalRegionList* regionList) {
	if (regionList != nullptr) {
		// ReadLocker rlocker(regionList);

		for (int i = 0; i < regionList->size(); ++i) {
			Reference<TerminalItemList*> itemList = regionList->get(i);

			if (itemList == nullptr)
				continue;

			terminals->add(itemList);
		}
	}
}