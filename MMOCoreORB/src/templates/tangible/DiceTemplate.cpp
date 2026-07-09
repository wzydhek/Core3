#include "DiceTemplate.h"

DiceTemplate::DiceTemplate() {
	sides = 0;
	sidesText = "";
	selfSingleResult = "";
	othersSingleResult = "";
	selfManyResult = "";
	othersManyResult = "";
}

DiceTemplate::~DiceTemplate() {
}

void DiceTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	sides = templateData->getIntField("sides");
	selfSingleResult = templateData->getStringField("selfSingleResult");
	othersSingleResult = templateData->getStringField("othersSingleResult");
	sidesText = templateData->getStringField("sidesText");
	selfManyResult = templateData->getStringField("selfManyResult");
	othersManyResult = templateData->getStringField("othersManyResult");
}

int DiceTemplate::getSides() {
	return sides;
}

String DiceTemplate::getSidesText() {
	return sidesText;
}

String DiceTemplate::getSelfSingleResult() {
	return selfSingleResult;
}

String DiceTemplate::getOthersSingleResult() {
	return othersSingleResult;
}

bool DiceTemplate::isDiceTemplate() {
	return true;
}

bool DiceTemplate::isChanceCube() {
	return sidesText == "chance cube";
}

bool DiceTemplate::isConfigurable() {
	return sidesText == "configurable dice";
}