#include "ValuesClasses.h"

Values::Values(const String& n, const float& tempmin, const float& tempmax, const float& tempcap, const int& prec, const bool& filler, const int& combine) {
	name = n;

	minValue = tempmin;
	maxValue = tempmax;
	capValue = tempcap;

	precision = prec;

	locked = false;

	values.put("maxPercentage", 0.0f);
	values.put("currentPercentage", 0.0f);
	values.put("currentValue", 0.0f);

	experimentalProperties = filler;
	combineType = combine;
}

Values::Values(const Values& val) : Object() {
	values = val.values;
	name = val.name;
	minValue = val.minValue;
	maxValue = val.maxValue;
	capValue = val.capValue;
	precision = val.precision;
	locked = val.locked;
	experimentalProperties = val.experimentalProperties;
	combineType = val.combineType;
}

Values::Values(Values&& val) : Object(), values(std::move(val.values)), name(std::move(val.name)), minValue(val.minValue), maxValue(val.maxValue), precision(val.precision), combineType(val.combineType), locked(val.locked), experimentalProperties(val.experimentalProperties) {
}

Values::~Values() {
}

float Values::getPercentage() const {
	return values.get("currentPercentage");
}

float Values::getValue() const {
	return values.get("currentValue");
}

float Values::getMaxPercentage() const {
	return values.get("maxPercentage");
}

float Values::getMinValue() const {
	return minValue;
}

float Values::getMaxValue() const {
	return maxValue;
}

float Values::getCapValue() const {
	return capValue;
}

int Values::getPrecision() const {
	return precision;
}

bool Values::isFiller() const {
	return experimentalProperties;
}

void Values::setFiller(bool in) {
	experimentalProperties = in;
}

const String& Values::getName() const {
	return name;
}

short Values::getCombineType() const {
	return combineType;
}

void Values::lockValue() {
	// minValue = getValue();
	// maxValue = getValue();
	locked = true;
}

void Values::unlockValue() {
	// why did this reset the values? that doesnt make sense locking it should freeze it not change it.
	// minValue = getValue();
	// maxValue = getValue();
	locked = false;
}

void Values::setValue(const float& value) {
	if (locked)
		return;

	float newpercentage;

	if (Float::areAlmostEqualRelative(maxValue, minValue)) {
		newpercentage = (value - minValue);

		const static Logger logger("ValuesClasses");

		logger.debug() << name << " value class has the same maxValue and minValue that are equal to: " << maxValue;
	} else if (maxValue > minValue) {
		newpercentage = (value - minValue) / (maxValue - minValue);
	} else {
		newpercentage = 1 - ((value - maxValue) / (minValue - maxValue));
	}

	if (newpercentage > values.get("maxPercentage"))
		newpercentage = values.get("maxPercentage");

	if (newpercentage < 0)
		newpercentage = 0;

	if (values.contains("currentValue")) {
		values.drop("currentValue");
	}

	if (values.contains("currentPercentage")) {
		values.drop("currentPercentage");
	}

	values.put("currentValue", value);
	values.put("currentPercentage", newpercentage);
}

void Values::setMinValue(const float& value) {
	if (locked)
		return;
	minValue = value;
}

void Values::setMaxValue(const float& value) {
	if (locked)
		return;
	maxValue = value;
}

void Values::setCapValue(const float& value) {
	if (locked)
		return;

	capValue = value;
}

void Values::setPrecision(const int& value) {
	if (locked)
		return;

	if (value < 0)
		return;

	precision = value;
}

void Values::setMaxPercentage(float& value) {
	if (locked)
		return;

	if (value > 100)
		value = 100;

	if (value < 0)
		value = 0;

	if (values.contains("maxPercentage")) {
		values.drop("maxPercentage");
	}

	values.put("maxPercentage", value);
}

void Values::setPercentage(float& value) {
	if (locked)
		return;

	if (value > values.get("maxPercentage"))
		value = values.get("maxPercentage");

	if (value < 0)
		value = 0;

	if (values.contains("currentPercentage")) {
		values.drop("currentPercentage");
	}

	values.put("currentPercentage", value);
}

void Values::setCombineType(short combine) {
	if (locked)
		return;

	combineType = combine;
}

void Values::resetValue() {
	float reset = (getMaxPercentage() * 10.0f) * (0.000015f * (getMaxPercentage() * 10.0f) + 0.015f);
	setPercentage(reset);

	float newvalue;
	if (maxValue > minValue)
		newvalue = (reset * (maxValue - minValue)) + minValue;
	else
		newvalue = ((1.0f - reset) * (minValue - maxValue)) + maxValue;
	setValue(newvalue);
}