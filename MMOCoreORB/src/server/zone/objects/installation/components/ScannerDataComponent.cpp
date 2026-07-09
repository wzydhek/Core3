#include "ScannerDataComponent.h"

ScannerDataComponent::ScannerDataComponent() {
	maxrange = 32;
	nextScanTime = time(0);
	this->setLoggingName("ScannerData");
}

void ScannerDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(maxrange);
	SERIALIZE_JSON_MEMBER(nextScanTime);
}

bool ScannerDataComponent::canScan() {
	return (time(0) > nextScanTime);
}

void ScannerDataComponent::updateCooldown() {
	nextScanTime = time(0) + scanCooldown;
}

bool ScannerDataComponent::isScannerData() {
	return true;
}