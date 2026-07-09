#include "FilterProceduralRule.h"

FilterProceduralRule::FilterProceduralRule(int type, uint32 formType) : featheringType(0), featheringAmount(0), filterType(0), internalType(type), formType(formType) {
}

FilterProceduralRule::~FilterProceduralRule() {
}

float FilterProceduralRule::process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect) {
	return 0;
}

void FilterProceduralRule::readObject(engine::util::IffStream* iffStream) {
	if (iffStream->openForm(formType) == nullptr)
		throw Exception("Incorrect form type " + String::valueOf(formType));

	parseFromIffStream(iffStream);

	iffStream->closeForm(formType);
}

void FilterProceduralRule::parseFromIffStream(engine::util::IffStream* iffStream) {
}

bool FilterProceduralRule::isEnabled() const {
	return informationHeader.isEnabled();
}

int FilterProceduralRule::getFeatheringType() const {
	return featheringType;
}

int FilterProceduralRule::getFilterType() const {
	return filterType;
}

int FilterProceduralRule::getInternalType() const {
	return internalType;
}

bool FilterProceduralRule::isType(int type) const {
	return internalType == type;
}