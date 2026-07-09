#include "AffectorExclude.h"

AffectorExclude::AffectorExclude() {
}

void AffectorExclude::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown AffectorExclude version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorExclude::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	iffStream->closeChunk('DATA');
}