/*
 * ScannerDataComponent.h
 *
 *  Created on: Nov 24, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class ScannerDataComponent : public DataObjectComponent, public Logger {
protected:
	int maxrange;
	uint64 nextScanTime;
	constexpr static uint64 scanCooldown = 20; // set to 60

public:
	ScannerDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool canScan();

	void updateCooldown();

	bool isScannerData();
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
