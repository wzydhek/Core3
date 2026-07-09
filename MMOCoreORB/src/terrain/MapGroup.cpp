#include "MapGroup.h"

MapGroup::MapGroup() {
	mfrcs.setNullValue(nullptr);
	mfrcs.setNoDuplicateInsertPlan();
}

MapGroup::~MapGroup() {
	while (mfams.size() > 0)
		delete mfams.remove(0);
}

void MapGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	iffStream->openForm(version);

	switch (version) {
		case '0000':
			parseFromIffStream(iffStream, Version<'0000'>());
			break;
		default:
			System::out << "unknown MGRP version " << version << endl;
			break;
	}

	iffStream->closeForm(version);
}

void MapGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		MapFamily* sfam = new MapFamily();
		sfam->readObject(iffStream);
		mfams.add(sfam);
		mfrcs.put(sfam->getVar1(), sfam->getMfrc());
	}
}

MapFractal* MapGroup::getMfrc(int index) {
	return mfrcs.get((uint32)index);
}

const MapFractal* MapGroup::getMfrc(int index) const {
	return mfrcs.get((uint32)index);
}