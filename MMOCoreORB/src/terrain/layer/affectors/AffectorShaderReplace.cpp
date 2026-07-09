#include "AffectorShaderReplace.h"

AffectorShaderReplace::AffectorShaderReplace() : oldShaderId(0), newShaderId(0), featheringType(0), featheringAmount(0) {
}

void AffectorShaderReplace::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown AffectorShaderReplace version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorShaderReplace::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	oldShaderId = iffStream->getInt();
	newShaderId = iffStream->getInt();
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}