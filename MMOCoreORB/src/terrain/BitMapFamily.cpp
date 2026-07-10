#include "BitmapFamily.h"
#include "templates/manager/DataArchiveStore.h"

BitMapFamily::BitMapFamily() : var1(0) {
}

void BitMapFamily::parseFromIffStream(engine::util::IffStream* iffStream) {
	iffStream->openChunk('DATA');

	var1 = iffStream->getInt();
	iffStream->getString(name);
	iffStream->getString(file);

	iffStream->closeChunk('DATA');

	int size = 0;
	byte* data = DataArchiveStore::instance()->getData(file, size);

	if (data != nullptr) {
		ObjectInputStream stream((char*)data, size);

		try {
			map.readObject(&stream);
		} catch (Exception& e) {
			Logger::console.error("could not parse targa file for BitMapFamily " + file);
			Logger::console.error(e.getMessage());
		}

		delete[] data;
	}
}

TargaBitmap* BitMapFamily::getMap() {
	return &map;
}

const String& BitMapFamily::getName() const {
	return name;
}

int BitMapFamily::getVar1() const {
	return var1;
}

const String& BitMapFamily::getFile() const {
	return file;
}