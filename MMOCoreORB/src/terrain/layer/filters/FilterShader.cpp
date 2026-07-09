#include "FilterShader.h"

FilterShader::FilterShader() : FilterProceduralRule(4, 'FSHD'), shaderId(0) {
}

void FilterShader::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown FilterShader version 0x" << hex << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void FilterShader::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	informationHeader.readObject(iffStream);

	iffStream->openChunk('DATA');

	shaderId = iffStream->getInt();

	iffStream->closeChunk('DATA');
}