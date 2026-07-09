/*
 * AuctionItemMap.h
 *
 *  Created on: Jun 11, 2012
 *      Author: kyle
 */

#pragma once

#include "TerminalListVector.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/auction/AuctionItem.h"

class AuctionTerminalMap : public VectorMap<uint64, Reference<TerminalItemList*> >, public Logger, public ReadWriteLock {

	TerminalGalaxyList galaxyListing;

public:
	AuctionTerminalMap();

	bool createTerminalListing(const String& planet, const String& region, SceneObject* vendor);

	bool dropTerminalListing(SceneObject* vendor);

	bool updateTerminalUID(const String& planet, const String& region, SceneObject* vendor, const String& newVuid);

	void updateTerminalSearch(SceneObject* vendor, bool enabled);

	TerminalListVector getTerminalData(const String& planet, const String& region, SceneObject* vendor);

	TerminalListVector getGalaxyListing();

	TerminalListVector getPlanetListing(const String& planet);


	TerminalListVector getRegionListing(const String& planet, const String& region);

private:
	bool addPlanetListing(const String& planet);

	bool removePlanetListing(const String& planet);

	bool addRegionListing(TerminalPlanetList* planetList, const String& region);

	bool removeRegionListing(TerminalPlanetList* planetList, const String& region);

	/// Pre Locked
	TerminalRegionList* getVendorRegion(SceneObject* vendor);

	void getPlanetListing(TerminalListVector* terminals, TerminalPlanetList* planetList);

	void getRegionListing(TerminalListVector* terminals, TerminalRegionList* regionList);

};
