/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "engine/service/proto/BaseMessage.h"

namespace templates {
namespace crafting {
namespace resourceweight {

class ResourceWeight : public Object {
private:

	Vector<uint8> properties;
	Vector<short> weights;
	Vector<float> percentages;

	String experimentalTitle;
	String propertyName;

	float minValue, maxValue;
	int precision;

	bool filler;

	short combineType;

public:
	ResourceWeight();

	~ResourceWeight();

	void addProperties(const String& title, const String& name, float min, float max, int prec, short combine);

	void addWeight(const String& property, int weight);

	void recalculatePercentages();

	uint8 convertStringValue(const String& property);


	void insertBatchToMessage(BaseMessage* msg);

	void insertToMessage(BaseMessage* msg);

	int getPropertyListSize();

	// Zero is returned if index is out of bounds
	uint8 getTypeAndWeight(int index);

	uint8 getBatchTypeAndWeight(int index);

	float getPropertyPercentage(int index);

	String getExperimentalTitle();

	String getPropertyName();

	float getMinValue();

	float getMaxValue();

	int getPrecision();

	bool isFiller();

	short getCombineType();

};

} // namespace resourceweight
} // namespace crafting
} // namespace templates

using namespace templates::crafting::resourceweight;
