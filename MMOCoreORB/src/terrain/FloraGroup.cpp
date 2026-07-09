#include "FloraGroup.h"

FloraGroup ::~FloraGroup() {
	while (data.size() > 0)
		delete data.remove(0);
}

void FloraGroup ::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0008':
			parseFromIffStream(iffStream, Version<'0008'>());
			break;
		default:
			System::out << "unknown FGRP version 0x" << hex << version;
			break;
	}

	iffStream->closeForm(version);
}

void FloraGroup ::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0008'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		FloraFamily* ffam = new FloraFamily();
		ffam->readObject(iffStream);

		data.add(ffam);
	}
}