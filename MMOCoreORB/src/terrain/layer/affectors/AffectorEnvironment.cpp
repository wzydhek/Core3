#include "AffectorEnvironment.h"

AffectorEnvironment::AffectorEnvironment() : environmentId(0), var2(0), weight(0) {
	affectorType = ENVIRONMENT;
}

void AffectorEnvironment::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown AffectorEnvironment version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorEnvironment::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	environmentId = iffStream->getInt();
	var2 = iffStream->getInt();
	weight = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}

void AffectorEnvironment::process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator) {
	// System::out << "processing AffectorEnvironment value:" << environmentId << endl;
	baseValue = (float)environmentId;
}

bool AffectorEnvironment::isEnabled() {
	return informationHeader.isEnabled();
}