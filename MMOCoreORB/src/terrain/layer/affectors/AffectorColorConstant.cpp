#include "AffectorColorConstant.h"

AffectorColorConstant::AffectorColorConstant() : id(0), r(0), g(0), b(0) {
}

void AffectorColorConstant::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown AffectorColorConstant version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorColorConstant::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	id = iffStream->getInt();
	r = iffStream->getByte();
	g = iffStream->getByte();
	b = iffStream->getByte();

	iffStream->closeChunk('DATA');
}