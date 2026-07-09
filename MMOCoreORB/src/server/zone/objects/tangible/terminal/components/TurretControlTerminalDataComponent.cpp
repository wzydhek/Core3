#include "TurretControlTerminalDataComponent.h"

TurretControlTerminalDataComponent::TurretControlTerminalDataComponent() {
	turretIndex = -1;
	suiBoxID = -1;
	addSerializableVariables();
}

TurretControlTerminalDataComponent::~TurretControlTerminalDataComponent() {
}

void TurretControlTerminalDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(turretIndex);
}

bool TurretControlTerminalDataComponent::isTurretControlTerminalData() {
	return true;
}

int TurretControlTerminalDataComponent::getTurrteIndex() const {
	return turretIndex;
}

void TurretControlTerminalDataComponent::setTurretIndex(int indx) {
	turretIndex = indx;
}

void TurretControlTerminalDataComponent::setSuiBoxID(unsigned int id) {
	suiBoxID = id;
}

unsigned int TurretControlTerminalDataComponent::getSuiBoxID() const {
	return suiBoxID;
}

void TurretControlTerminalDataComponent::addSerializableVariables() {
	addSerializableVariable("turretIndex", &turretIndex);
}