#include "HeroRingDataComponent.h"

HeroRingDataComponent::HeroRingDataComponent() {
	charges = 50;
	addSerializableVariables();
}

HeroRingDataComponent::~HeroRingDataComponent() {
}

void HeroRingDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(charges);
}

void HeroRingDataComponent::setCharges(int num) {
	charges = num;
}

int HeroRingDataComponent::getCharges() {
	return charges;
}

bool HeroRingDataComponent::isHeroRingData() {
	return true;
}

void HeroRingDataComponent::addSerializableVariables() {
	addSerializableVariable("charges", &charges);
}