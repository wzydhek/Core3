#include "AffectorFloraNonCollidableConstant.h"

AffectorFloraNonCollidableConstant::AffectorFloraNonCollidableConstant() : familyId(0), var2(0), flag(0), featheringType(0), featheringAmount(0) {
}

void AffectorFloraNonCollidableConstant::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0004':
			parseFromIffStream(iffStream, Version<'0004'>());
			break;
		default:
			System::out << "unknown AffectorFloraNonCollidableConstant version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorFloraNonCollidableConstant::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0004'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	familyId = iffStream->getInt();
	var2 = iffStream->getInt();
	flag = iffStream->getInt();
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}