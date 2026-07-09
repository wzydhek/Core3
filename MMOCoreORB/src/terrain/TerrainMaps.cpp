#include "TerrainMaps.h"

void TerrainMaps::readObject(engine::util::IffStream* iffStream) {
	parseFromIffStream(iffStream);
}

void TerrainMaps::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			break; // valid version, no maps inside, so no parsing
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown MAPS version " << String::valueOf(version);
			break;
	}

	iffStream->closeForm(version);
}

void TerrainMaps::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	iffStream->openChunk('DATA');

	var1 = iffStream->getFloat();
	var2 = iffStream->getFloat();
	var3 = iffStream->getInt();
	var4 = iffStream->getInt();

	iffStream->closeChunk('DATA');

	waterMap.readObject(iffStream);
	seedMap.readObject(iffStream);
}