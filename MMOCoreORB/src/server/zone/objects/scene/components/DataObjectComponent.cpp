/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#include "DataObjectComponent.h"
#include "server/zone/objects/scene/SceneObject.h"

DataObjectComponent::DataObjectComponent() {

}

DataObjectComponent::~DataObjectComponent() {

}

void DataObjectComponent::initializeTransientMembers() {

}

void DataObjectComponent::notifyObjectDestroyingFromDatabase() {

}

void DataObjectComponent::setParent(SceneObject* object) {
	parent = object;
}

SceneObject* DataObjectComponent::getParent() {
	return parent.get().get();
}

void server::zone::objects::scene::components::to_json(nlohmann::json& j, const DataObjectComponent& comp) {
	comp.writeJSON(j);
}

void DataObjectComponent::writeJSON(nlohmann::json& j) const {
	j["parent"] = parent;
}

bool DataObjectComponent::isDiceData() {
	return false;
}

bool DataObjectComponent::isFireworkShowData() {
	return false;
}

bool DataObjectComponent::isVendorData() {
	return false;
}

bool DataObjectComponent::isAuctionTerminalData() {
	return false;
}

bool DataObjectComponent::isCreatureHabitatData() {
	return false;
}

bool DataObjectComponent::isBuildingData() {
	return false;
}

bool DataObjectComponent::isDestructibleBuildingData() {
	return false;
}

bool DataObjectComponent::isTurretData() {
	return false;
}

bool DataObjectComponent::isScannerData() {
	return false;
}

bool DataObjectComponent::isGCWBaseData() {
	return false;
}

bool DataObjectComponent::isSecurityTerminalData() {
	return false;
}

bool DataObjectComponent::isMinefieldData() {
	return false;
}

bool DataObjectComponent::isTurretControlTerminalData() {
	return false;
}

bool DataObjectComponent::isDecoration() {
	return false;
}

bool DataObjectComponent::isCoaMessageData() {
	return false;
}

bool DataObjectComponent::isEventPerkData() {
	return false;
}

bool DataObjectComponent::isFlagGameData() {
	return false;
}

bool DataObjectComponent::isDataStorageUnitData() {
	return false;
}

bool DataObjectComponent::isDroidModuleData() {
	return false;
}

bool DataObjectComponent::isGamblingTerminalData() {
	return false;
}