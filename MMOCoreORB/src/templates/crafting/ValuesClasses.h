/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "engine/log/Logger.h"

/*
 * The Values class is just a container for values calculated in crafting
 * Each "Value" has 3 properties, maxPercentage, currentPercentage, currentValue.
 * These values coupled with the traits minValue and maxValue allow a generic holder for
 * whatever value the crafting process needs on any range
 */
class Values : public Object {
	VectorMap<String, float> values;
	String name;
	float minValue, maxValue, capValue;
	short precision;
	short combineType;
	bool locked;
	bool experimentalProperties;

public:
	Values() = delete;

	Values(const String& n, const float& tempmin, const float& tempmax, const float& tempcap, const int& prec, const bool& filler, const int& combine);

	Values(const Values& val);

	Values(Values&& val);

	~Values();

	float getPercentage() const;

	float getValue() const;

	float getMaxPercentage() const;

	float getMinValue() const;

	float getMaxValue() const;

	float getCapValue() const;

	int getPrecision() const;

	bool isFiller() const;

	void setFiller(bool in);

	const String& getName() const;

	short getCombineType() const;

	void lockValue();

	void unlockValue();

	void setValue(const float& value);

	void setMinValue(const float& value);

	void setMaxValue(const float& value);

	void setCapValue(const float& value);

	void setPrecision(const int& value);

	void setMaxPercentage(float& value);

	void setPercentage(float& value);

	void setCombineType(short combine);

	void resetValue();

};
