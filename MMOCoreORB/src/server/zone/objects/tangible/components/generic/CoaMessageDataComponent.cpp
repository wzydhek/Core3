#include "CoaMessageDataComponent.h"

CoaMessageDataComponent::CoaMessageDataComponent() {
	number = 1;
	addSerializableVariables();
}

CoaMessageDataComponent::~CoaMessageDataComponent() {
}

void CoaMessageDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(faction);
	SERIALIZE_JSON_MEMBER(number);
}

void CoaMessageDataComponent::setFaction(String side) {
	faction = side;
}

void CoaMessageDataComponent::setNumber(int num) {
	number = num;
}

String CoaMessageDataComponent::getFaction() {
	return faction;
}

int CoaMessageDataComponent::getNumber() {
	return number;
}

bool CoaMessageDataComponent::isCoaMessageData() {
	return true;
}

void CoaMessageDataComponent::addSerializableVariables() {
	addSerializableVariable("faction", &faction);
	addSerializableVariable("number", &number);
}