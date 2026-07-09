#include "FilterHeight.h"

FilterHeight::FilterHeight() : FilterProceduralRule(0, 'FHGT'), minHeight(0), maxHeight(0) {
	filterType = HEIGHTTYPE;
}

void FilterHeight::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0002':
			parseFromIffStream(iffStream, Version<'0002'>());
			break;
		default:
			System::out << "unknown FilterHeight version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void FilterHeight::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	minHeight = iffStream->getFloat();
	maxHeight = iffStream->getFloat();
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}

float FilterHeight::process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator, FilterRectangle* rect) {
	float result;

	if ((baseValue > minHeight) && (baseValue < maxHeight)) {
		float v9 = (maxHeight - minHeight) * featheringAmount * 0.5;

		if (minHeight + v9 <= baseValue) {
			if (maxHeight - v9 >= baseValue) {
				result = 1.0;
			} else
				result = (maxHeight - baseValue) / v9;

		} else {
			result = (baseValue - minHeight) / v9;
		}
	} else
		result = 0;

	return result;
}