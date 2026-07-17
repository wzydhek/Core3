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

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace vendor {

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

} // namespace vendor
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::vendor;
