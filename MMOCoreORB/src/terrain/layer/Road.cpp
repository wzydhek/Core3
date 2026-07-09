#include "Road.h"

Road::Road() : IffTemplateVariable() {
}

Road::~Road() {
	for (int i = 0; i < sgmts.size(); ++i)
		delete sgmts.get(i);
}

void Road::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0001':
			parseFromIffStream(iffStream, Version<'0001'>());
			break;
		default:
			System::out << "unknown Road version " << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void Road::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; i++) {
		Segment* sgmt = new Segment();
		sgmt->readObject(iffStream);

		sgmts.add(sgmt);
	}

	// Logger::console.info(true) << "Road finished loading segments - Total Segments: " << sgmts.size();
}