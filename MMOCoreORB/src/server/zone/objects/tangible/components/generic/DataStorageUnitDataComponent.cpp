#include "DataStorageUnitDataComponent.h"

DataStorageUnitDataComponent::DataStorageUnitDataComponent() {
	// There are 12 text options (1-12).  Pick one at random
	id = System::random(11) + 1;
	addSerializableVariables();
}

DataStorageUnitDataComponent::~DataStorageUnitDataComponent() {
}

void DataStorageUnitDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(id);
}

byte DataStorageUnitDataComponent::getId() const {
	return id;
}

bool DataStorageUnitDataComponent::isDataStorageUnitData() {
	return true;
}

void DataStorageUnitDataComponent::addSerializableVariables() {
	addSerializableVariable("id", &id);
}