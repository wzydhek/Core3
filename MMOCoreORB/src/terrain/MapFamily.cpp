#include "MapFamily.h"

MapFamily::MapFamily() : var1(0) {
}

void MapFamily::parseFromIffStream(engine::util::IffStream* iffStream) {
	iffStream->openChunk('DATA');

	var1 = iffStream->getInt();
	iffStream->getString(var2);

	iffStream->closeChunk('DATA');

	mfrc.readObject(iffStream);
}

MapFractal* MapFamily::getMfrc() {
	return &mfrc;
}

const MapFractal* MapFamily::getMfrc() const {
	return &mfrc;
}

int MapFamily::getVar1() const {
	return var1;
}

const String& MapFamily::getName() const {
	return var2;
}
