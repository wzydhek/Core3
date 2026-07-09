#include "AffectorShaderConstant.h"

AffectorShaderConstant::AffectorShaderConstant() : familyId(0), featheringType(0), featheringAmount(0) {
}

void AffectorShaderConstant::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown AffectorShaderConstant version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorShaderConstant::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	familyId = iffStream->getInt();
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}