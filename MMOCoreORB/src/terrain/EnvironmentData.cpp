#include "EnvironmentData.h"

EnvironmentData::EnvironmentData() : environmentId(0), var3(0), var4(0), var5(0), var6(0) {
}

void EnvironmentData::parseFromIffStream(engine::util::IffStream* iffStream) {
	iffStream->openChunk('DATA');

	environmentId = iffStream->getInt();

	iffStream->getString(environmentName);

	var3 = iffStream->getByte();
	var4 = iffStream->getByte();
	var5 = iffStream->getByte();
	var6 = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}