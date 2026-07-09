/*
 * ScannerDataComponent.h
 *
 *  Created on: Nov 24, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

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
