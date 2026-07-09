#include "BitmapGroup.h"

BitmapGroup::BitmapGroup() {
}

BitmapGroup::~BitmapGroup() {
	while (mfams.size() > 0)
		delete mfams.remove(0);
}

void BitmapGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
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

void BitmapGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		BitMapFamily* sfam = new BitMapFamily();
		sfam->readObject(iffStream);
		mfams.add(sfam);
		mfrcs.put(sfam->getVar1(), sfam->getMap());
	}
}

TargaBitmap* BitmapGroup::getBitmap(int index) {
	return mfrcs.get((uint32)index);
}