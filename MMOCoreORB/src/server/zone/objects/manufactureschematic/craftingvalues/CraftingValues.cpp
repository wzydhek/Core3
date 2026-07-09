/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "CraftingValues.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

CraftingValues::CraftingValues() {
	doHide = true;
	setLoggingName("CraftingValues");
	setLogging(false);
}


CraftingValues::CraftingValues(const CraftingValues& values) : Object(), Serializable(), Logger(), slots(values.slots) {
	valuesToSend = values.valuesToSend;
	doHide = values.doHide;
	schematic = values.schematic;
	player = values.player;
	attributesMap = values.attributesMap;

	setLoggingName("CraftingValues");
	setLogging(false);
}

CraftingValues::CraftingValues(const AttributesMap& values) : Object(), Serializable(), Logger() {
	doHide = true;

	int totalAttributes = values.getSize();

	for (int i = 0; i < totalAttributes; ++i) {
		String attribute = values.getAttribute(i);

		attributesMap.addExperimentalAttribute(attribute, values.getAttributeGroup(attribute), values.getMinValue(attribute), values.getMaxValue(attribute), values.getPrecision(attribute), values.isHidden(attribute), values.getCombineType(attribute));
		attributesMap.setMaxPercentage(attribute, 1.f);
	}

	setLoggingName("CraftingValues");
	setLogging(false);
}

CraftingValues::~CraftingValues() {
	schematic = nullptr;
	player = nullptr;
}

void CraftingValues::setManufactureSchematic(ManufactureSchematic* manu) {
	schematic = manu;
}

ManufactureSchematic* CraftingValues::getManufactureSchematic() {
	return schematic.get();
}

void CraftingValues::setPlayer(CreatureObject* play) {
	player = play;
}

CreatureObject* CraftingValues::getPlayer() {
	return player.get();
}

void CraftingValues::recalculateValues(bool initial) {
	// info(true) << "---------- CraftingValues::recalculateValues ----------";

	float percentage = 0.f, min = 0.f, max = 0.f, newValue = 0.f, oldValue = 0.f;
	bool hidden = false;

	// info(true) << " Total Experimental Attributes: " << getTotalExperimentalAttributes();

	for (int i = 0; i < getTotalExperimentalAttributes(); ++i) {
		String attribute = getAttribute(i);
		String group = getAttributeGroup(attribute);

		min = getMinValue(attribute);
		max = getMaxValue(attribute);

		hidden = isHidden(attribute);

		percentage = getCurrentPercentage(attribute);

		oldValue = getCurrentValue(attribute);

		// info(true) << "Attribute: " << attribute <<  " Group: " << group << " Old Value: " << oldValue << " Min: " << min << " Max: " << max;

		if (group == "") {
			if (max > min)
				newValue = max;
			else
				newValue = min;
		} else if(max != min) {
			if (max > min)
				newValue = (percentage * (max - min)) + min;
			else
				newValue = (float(1.0f - percentage) * (min - max)) + max;
		} else if(max == min) {
			newValue = max;
		}

		// info(true) << "Setting Attribute: " << attribute << " New Value: " << newValue;

		if (initial || (newValue != oldValue && !initial && !hidden)) {
			setCurrentValue(attribute, newValue);
			valuesToSend.add(attribute);
		}
	}

	// info(true) << "---------- END CraftingValues::recalculateValues ----------";
}

void CraftingValues::clearAll() {
	doHide = true;
	attributesMap.removeAll();
	valuesToSend.removeAll();
	schematic = nullptr;
	player = nullptr;
	clearSlots();
}

String CraftingValues::toString() const {
	StringBuffer str;

	for (int i = 0;i < attributesMap.getSize(); ++i) {
		String attribute = attributesMap.getAttribute(i);

		str << "\n*************************" << endl;
		str << "Attribute #" << i << " Name: " << attribute << endl;
		str << "Group: " << attributesMap.getAttributeGroup(attribute) << endl;
		str << "**************************" << endl;
	}

	return str.toString();
}

// new Implementation of AttributesMap
void CraftingValues::addExperimentalAttribute(const String& attribute, const String& group, const float min, const float max, const int precision, const bool filler, const int combine) {
	attributesMap.addExperimentalAttribute(attribute, group, min, max, precision, filler, combine);
}

const String& CraftingValues::getAttribute(const int i) const {
	return attributesMap.getAttribute(i);
}

const String& CraftingValues::getAttributeGroup(const String& attribute) const {
	return attributesMap.getAttributeGroup(attribute);
}

const String& CraftingValues::getVisibleAttributeGroup(const int i) const {
	return attributesMap.getVisibleAttributeGroup(i);
}

int CraftingValues::getTotalExperimentalAttributes() const {
	return attributesMap.getSize();
}

bool CraftingValues::hasExperimentalAttribute(const String& attribute) const {
	return attributesMap.hasExperimentalAttribute(attribute);
}

bool CraftingValues::isHidden(const String& attribute) const {
	return attributesMap.isHidden(attribute);
}

void CraftingValues::setHidden(const String& attribute) {
	attributesMap.setHidden(attribute);
}

void CraftingValues::unsetHidden(const String& attribute) {
	attributesMap.unsetHidden(attribute);
}

short CraftingValues::getCombineType(const String& attribute) const {
	return attributesMap.getCombineType(attribute);
}

void CraftingValues::setCurrentValue(const String& attribute, const float value) {
	attributesMap.setCurrentValue(attribute, value);
}

void CraftingValues::setCurrentValue(const String& attribute, const float value, const float min, const float max) {
	attributesMap.setCurrentValue(attribute, value, min, max);
}

float CraftingValues::getCurrentValue(const String& attribute) const {
	return attributesMap.getCurrentValue(attribute);
}

float CraftingValues::getCurrentValue(const int i) const {
	return attributesMap.getCurrentValue(i);
}

void CraftingValues::lockValue(const String& attribute) {
	attributesMap.lockValue(attribute);
}

void CraftingValues::unlockValue(const String& attribute) {
	attributesMap.unlockValue(attribute);
}

void CraftingValues::resetValue(const String& attribute) {
	attributesMap.resetValue(attribute);
}

void CraftingValues::setCurrentPercentage(const String& subtitle, const float value) {
	attributesMap.setCurrentPercentage(subtitle, value);
}

void CraftingValues::setCurrentPercentage(const String& subtitle, const float value, const float max) {
	attributesMap.setCurrentPercentage(subtitle, value, max);
}

float CraftingValues::getCurrentPercentage(const String& attribute) const {
	return attributesMap.getCurrentPercentage(attribute);
}

float CraftingValues::getCurrentPercentage(const int i) const {
	return attributesMap.getCurrentPercentage(i);
}

float CraftingValues::getCurrentVisiblePercentage(const String title) const {
	return attributesMap.getCurrentVisiblePercentage(title);
}

void CraftingValues::setMaxPercentage(const String& attribute, const float value) {
	attributesMap.setMaxPercentage(attribute, value);
}

float CraftingValues::getMaxPercentage(const String& attribute) const {
	return attributesMap.getMaxPercentage(attribute);
}

float CraftingValues::getMaxPercentage(const int i) const {
	return attributesMap.getMaxPercentage(i);
}

float CraftingValues::getMaxVisiblePercentage(const int i) const {
	return attributesMap.getMaxVisiblePercentage(i);
}

float CraftingValues::getMinValue(const String& attribute) const {
	return attributesMap.getMinValue(attribute);
}

float CraftingValues::getMaxValue(const String& attribute) const {
	return attributesMap.getMaxValue(attribute);
}

float CraftingValues::getCapValue(const String& attribute) const {
	return attributesMap.getCapValue(attribute);
}

void CraftingValues::setMinValue(const String& attribute, const float value) {
	attributesMap.setMinValue(attribute, value);
}

void CraftingValues::setMaxValue(const String& attribute, const float value) {
	attributesMap.setMaxValue(attribute, value);
}

void CraftingValues::setCapValue(const String& attribute, const float value) {
	attributesMap.setCapValue(attribute, value);
}

int CraftingValues::getPrecision(const String& attribute) const {
	return attributesMap.getPrecision(attribute);
}

void CraftingValues::setPrecision(const String& attribute, const int precision) {
	attributesMap.setPrecision(attribute, precision);
}

int CraftingValues::getTotalVisibleAttributeGroups() const {
	return attributesMap.getTotalVisibleAttributeGroups();
}

void CraftingValues::setSlot(const String& value, bool filled) {
	slots.put(value, filled);
}

void CraftingValues::clearSlots() {
	slots.removeAll();
}

bool CraftingValues::hasSlotFilled(const String& name) const {
	if (!slots.contains(name))
		return false;

	return slots.get(name);
}

void CraftingValues::addValueToSend(const String& name) {
	valuesToSend.add(name);
}

int CraftingValues::getValuesToSendSize() const {
	return valuesToSend.size();
}

const String& CraftingValues::getValuesToSend(const int i) const {
	return valuesToSend.get(i);
}

float CraftingValues::getAttributeAndValue(const String& attribute, const int i) const {
	String attributeName = getAttribute(i);

	return getCurrentValue(attributeName);
}

// Clear
void CraftingValues::clear() {
	valuesToSend.removeAll();
}