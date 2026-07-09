#include "AffectorPassable.h"

AffectorPassable::AffectorPassable() : var1(0), var2(0) {
}

void AffectorPassable::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown AffectorPAS version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorPassable::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	var1 = iffStream->getByte();
	var2 = iffStream->getInt();

	iffStream->closeChunk('DATA');
}