#include "Boundary.h"

Boundary::Boundary(uint32 formType) : formType(formType) {
}

Boundary::~Boundary() {
}

void Boundary::executeRule(ProceduralTerrainAppearance* generator) {
}

void Boundary::readObject(engine::util::IffStream* iffStream) {
	if (iffStream->openForm(formType) == nullptr)
		throw Exception("Incorrect form type " + String::valueOf(formType));

	parseFromIffStream(iffStream);

	iffStream->closeForm(formType);
}

float Boundary::getLocalWaterTableHeight() const {
	return -16000;
}

int Boundary::getFeatheringType() const {
	return featheringType;
}

bool Boundary::isEnabled() const {
	return informationHeader.isEnabled();
}