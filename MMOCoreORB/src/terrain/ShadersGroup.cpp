#include "ShadersGroup.h"

ShadersGroup::ShadersGroup() {
}

ShadersGroup::~ShadersGroup() {
	while (data.size() > 0)
		delete data.remove(0);
}

void ShadersGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0006':
			parseFromIffStream(iffStream, Version<'0006'>());
			break;
		default:
			System::out << "unknown SGRP version " << version;
			break;
	}

	iffStream->closeForm(version);
}

void ShadersGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0006'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		ShaderFamily* sfam = new ShaderFamily();
		sfam->readObject(iffStream);
		data.add(sfam);
	}
}