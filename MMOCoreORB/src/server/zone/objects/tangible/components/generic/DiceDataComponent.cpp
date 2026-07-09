#include "DiceDataComponent.h"

DiceDataComponent::DiceDataComponent() {
	sides = 0;
	addSerializableVariables();
}

DiceDataComponent::~DiceDataComponent() {
}

void DiceDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(sides);
}

void DiceDataComponent::setSides(byte count) {
	sides = count;
}

byte DiceDataComponent::getSides() const {
	return sides;
}

bool DiceDataComponent::isDiceData() {
	return true;
}

void DiceDataComponent::addSerializableVariables() {
	addSerializableVariable("sides", &sides);
}