#include "AffectorRCN.h"

AffectorRCN::AffectorRCN() : familyId(0), var2(0), flag(0), featheringType(0), featheringAmount(0) {
}

void AffectorRCN::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0002':
			parseFromIffStream(iffStream, Version<'0002'>());
			break;
		default:
			System::out << "unknown AffectorRCN version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void AffectorRCN::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	familyId = iffStream->getInt();
	var2 = iffStream->getInt();
	flag = iffStream->getInt();
	featheringType = iffStream->getInt();
	featheringAmount = iffStream->getFloat();

	iffStream->closeChunk('DATA');
}