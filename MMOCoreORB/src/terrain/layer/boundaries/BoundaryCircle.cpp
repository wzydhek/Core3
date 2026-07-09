#include "BoundaryCircle.h"

BoundaryCircle::BoundaryCircle() : Boundary('BCIR'), centerX(0), centerY(0), radius(0), radiusSquared(0) {
	// ruleType = BOUNDARYCIRCLE;
}

void BoundaryCircle::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0002':
			parseFromIffStream(iffStream, Version<'0002'>());
			break;
		default:
			System::out << "unknown BoundaryCircle version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void BoundaryCircle::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	// 5 vars

	centerX = iffStream->getFloat();
	centerY = iffStream->getFloat();
	radius = iffStream->getFloat();
	radiusSquared = radius * radius;
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	if (featheringAmount < 0)
		featheringAmount = 0;
	else if (featheringAmount > 1)
		featheringAmount = 1;

	iffStream->closeChunk('DATA');
}

float BoundaryCircle::checkInfluence(float x, float y) const {
	float v3 = centerX - x;
	float v4 = centerY - y;
	float result;

	float v8 = v4 * v4 + v3 * v3;

	if (v8 <= radiusSquared) {
		float v7 = (1.0 - featheringAmount) * radius;
		float v6 = v7 * v7;

		if (v8 > v6)
			result = 1.0 - (v8 - v6) / (radiusSquared - v6);
		else
			result = 1.0;

	} else {
		result = 0.0;
	}

	return result;
}

bool BoundaryCircle::containsPoint(float x, float y) const {
	return checkInfluence(x, y) != 0;
}

float BoundaryCircle::process(float x, float y) const {
	return checkInfluence(x, y);
}

void BoundaryCircle::translateBoundary(float x, float y) {
	centerX += x;
	centerY += y;
}

float BoundaryCircle::getMinX() const {
	return centerX - radius;
}

float BoundaryCircle::getMaxX() const {
	return centerX + radius;
}

float BoundaryCircle::getMinY() const {
	return centerY - radius;
}

float BoundaryCircle::getMaxY() const {
	return centerY + radius;
}