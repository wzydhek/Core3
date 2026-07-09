#include "RacialCreationData.h"

RacialCreationData::RacialCreationData() {
	totalAttributes = 0;
}

RacialCreationData::RacialCreationData(const RacialCreationData& cd) : Object() {
	minAttributes = cd.minAttributes;
	maxAttributes = cd.maxAttributes;
	modAttributes = cd.modAttributes;
	totalAttributes = cd.totalAttributes;
}

RacialCreationData& RacialCreationData::operator=(const RacialCreationData& cd) {
	if (this == &cd)
		return *this;

	minAttributes = cd.minAttributes;
	maxAttributes = cd.maxAttributes;
	modAttributes = cd.modAttributes;
	totalAttributes = cd.totalAttributes;

	return *this;
}

void RacialCreationData::parseAttributeData(const DataTableRow* row) {
	// The data starts at offset 2.
	int min = 0;
	int max = 0;

	for (int i = 2; i < 20; i += 2) {
		row->getValue(i, min);
		row->getValue(i + 1, max);

		minAttributes.add(min);
		maxAttributes.add(max);
	}

	row->getValue(20, totalAttributes);
}

void RacialCreationData::parseRacialModData(const DataTableRow* row) {
	int mod = 0;

	for (int i = 2; i < 11; ++i) {
		row->getValue(i, mod);

		modAttributes.add(mod);
	}
}

int RacialCreationData::getAttributeMin(int idx) const {
	return minAttributes.get(idx);
}

int RacialCreationData::getAttributeMax(int idx) const {
	return maxAttributes.get(idx);
}

int RacialCreationData::getAttributeMod(int idx) const {
	return modAttributes.get(idx);
}

int RacialCreationData::getAttributeTotal() const {
	return totalAttributes;
}

String RacialCreationData::toString() const {
	StringBuffer str;

	for (int i = 0; i < minAttributes.size(); ++i)
		str << "min[" << i << "]:" << minAttributes.get(i) << ";";

	for (int i = 0; i < maxAttributes.size(); ++i)
		str << "max[" << i << "]:" << maxAttributes.get(i) << ";";

	for (int i = 0; i < modAttributes.size(); ++i)
		str << "mod[" << i << "]:" << modAttributes.get(i) << ";";

	return str.toString();
}