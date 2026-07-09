#include "RadialGroup.h"

RadialGroup::~RadialGroup() {
	while (data.size() > 0)
		delete data.remove(0);
}

void RadialGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0003':
			parseFromIffStream(iffStream, Version<'0003'>());
			break;
		default:
			System::out << "unknown RGRP version " << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void RadialGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0003'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		RadialFamily* ffam = new RadialFamily();
		ffam->readObject(iffStream);

		data.add(ffam);
	}
}