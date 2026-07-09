#include "AffectorColorRampFractal.h"

AffectorColorRampFractal::AffectorColorRampFractal() : familyId(0), var2(0) {
}

void AffectorColorRampFractal::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown AffectorColorRampFractal version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorColorRampFractal::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	informationHeader.readObject(iffStream);

	iffStream->openForm('DATA');

	iffStream->openChunk('PARM');

	familyId = iffStream->getInt();
	var2 = iffStream->getByte();

	iffStream->getString(shaderFile);

	iffStream->closeChunk('PARM');

	iffStream->closeForm('DATA');
}