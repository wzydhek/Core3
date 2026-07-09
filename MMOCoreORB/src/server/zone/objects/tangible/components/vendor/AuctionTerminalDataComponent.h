/*
 * AuctionTerminalDataComponent.h
 *
 *  Created on: 5/27/2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/managers/auction/AuctionManager.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/Zone.h"

class AuctionTerminalDataComponent : public DataObjectComponent {
protected:

	ManagedWeakReference<AuctionManager*> auctionMan;
	SerializableString uid;

public:
	AuctionTerminalDataComponent();

	virtual ~AuctionTerminalDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void initializeTransientMembers();

	void updateUID();

	String getUID();

	bool isAuctionTerminalData();

private:
	void addSerializableVariables();
};
