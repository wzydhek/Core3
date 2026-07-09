#include "EnvironmentGroup.h"

EnvironmentGroup::EnvironmentGroup() {
}

EnvironmentGroup::~EnvironmentGroup() {
	for (int i = 0; i < data.size(); ++i)
		delete data.get(i);
}

void EnvironmentGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0002':
			parseFromIffStream(iffStream, Version<'0002'>());
			break;
		default:
			System::out << "unknown EGRP version 0x" << hex << version;
			break;
	}

	iffStream->closeForm(version);
}

void EnvironmentGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		EnvironmentData* efamData = new EnvironmentData();
		efamData->readObject(iffStream);

		data.add(efamData);
	}
}