#include "FilterDirection.h"

FilterDirection::FilterDirection() : FilterProceduralRule(3, 'FDIR'), minDegree(0), min(0), maxDegree(0), max(0) {
	filterType = 0;
}

void FilterDirection::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown FilterDirection version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void FilterDirection::setMinDegree(float deg) {
	minDegree = deg;

	if (-M_PI >= minDegree) {
		minDegree = -M_PI;
	}

	min = minDegree * 1 / (2 * M_PI);
}

void FilterDirection::setMaxDegree(float deg) {
	maxDegree = deg;

	if (deg >= M_PI) {
		maxDegree = M_PI;
	}

	max = maxDegree * 1 / (2 * M_PI);
}

void FilterDirection::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	minDegree = iffStream->getFloat();
	setMinDegree(minDegree);

	// setMinAngle(M_PI * minDegree * 0.005555555690079927);

	maxDegree = iffStream->getFloat();
	setMaxDegree(maxDegree);

	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}