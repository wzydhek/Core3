#include "PowerupStat.h"

PowerupStat::PowerupStat() {
	value = 0;

	addSerializableVariables();
}

PowerupStat::PowerupStat(const PowerupStat& p) : Object(), Serializable() {
	attributeToModify = p.attributeToModify;
	name = p.name;
	pupAttribute = p.pupAttribute;
	value = p.value;

	addSerializableVariables();
}

PowerupStat::PowerupStat(const String& att, const String& n, const String& p) {
	attributeToModify = att;
	name = n;
	pupAttribute = p;
	value = 0;

	addSerializableVariables();
}

PowerupStat& PowerupStat::operator=(const PowerupStat& p) {
	if (this == &p)
		return *this;

	attributeToModify = p.attributeToModify;
	name = p.name;
	pupAttribute = p.pupAttribute;
	value = p.value;

	return *this;
}

bool PowerupStat::operator==(const PowerupStat& stat) {
	if (this == &stat)
		return true;

	return ((attributeToModify == stat.attributeToModify) && (name == stat.name) && (pupAttribute == stat.pupAttribute));
}

void PowerupStat::addSerializableVariables() {
	addSerializableVariable("attributeToModify", &attributeToModify);
	addSerializableVariable("name", &name);
	addSerializableVariable("pupAttribute", &pupAttribute);
	addSerializableVariable("value", &value);
}

const String& PowerupStat::getAttributeToModify() const {
	return attributeToModify;
}

const String& PowerupStat::getName() const {
	return name;
}

const String& PowerupStat::getPupAttribute() const {
	return pupAttribute;
}

float PowerupStat::getValue() const {
	return value;
}

void PowerupStat::setValue(float v) {
	value = v;
}