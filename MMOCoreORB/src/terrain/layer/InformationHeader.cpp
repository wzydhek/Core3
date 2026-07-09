#include "InformationHeader.h"

InformationHeader::InformationHeader() : IffTemplateVariable(), var1(0) {
}

void InformationHeader::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown InformationHeader version " << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void InformationHeader::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	iffStream->openChunk('DATA');

	var1 = iffStream->getInt();
	iffStream->getString(description);

	iffStream->closeChunk('DATA');
}

bool InformationHeader::isEnabled() const {
	return var1 != 0;
}

String& InformationHeader::getDescription() {
	return description;
}

const String& InformationHeader::getDescription() const {
	return description;
}