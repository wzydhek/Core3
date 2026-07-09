#include "AppearanceTemplate.h"

uint32 AppearanceTemplate::getType() const {
	return 'APPR';
}

const String& AppearanceTemplate::getFloorMesh() const {
	return floorName;
}

const BaseBoundingVolume* AppearanceTemplate::getBoundingVolume() const {
	return volume;
}

const VectorMap<String, Matrix4>& AppearanceTemplate::getHardpoints() const {
	return hardpoints;
}

const BaseBoundingVolume* AppearanceTemplate::getCollisionVolume() const {
	return collisionVolume;
}

const String& AppearanceTemplate::getFileName() const {
	return fileName;
}

void AppearanceTemplate::readObject(IffStream* iffStream) {
	fileName = iffStream->getFileName();

	iffStream->openForm('APPR');
	uint32 formType = iffStream->getNextFormType();
	if (formType == '0003') {
		iffStream->openForm('0003');
		volume = BoundingVolumeFactory::getVolume(iffStream);
		collisionVolume = BoundingVolumeFactory::getVolume(iffStream);

		Chunk* chunk = iffStream->openForm('HPTS');
		try {
			int numHardpoints = chunk->getChunksSize();
			for (int i = 0; i < numHardpoints; i++) {
				iffStream->openChunk('HPNT');
				Matrix4 transform;
				transform[0][0] = iffStream->getFloat();
				transform[0][1] = iffStream->getFloat();
				transform[0][2] = iffStream->getFloat();

				transform[3][0] = iffStream->getFloat();

				transform[1][0] = iffStream->getFloat();
				transform[1][1] = iffStream->getFloat();
				transform[1][2] = iffStream->getFloat();

				transform[3][1] = iffStream->getFloat();

				transform[2][0] = iffStream->getFloat();
				transform[2][1] = iffStream->getFloat();
				transform[2][2] = iffStream->getFloat();

				transform[3][2] = iffStream->getFloat();

				String name;
				iffStream->getString(name);
				hardpoints.put(name, transform);
				// Logger::console.info(fileName + " Loading hardpoint: " + name + " Transform: " + toString(transform), true);
				iffStream->closeChunk('HPNT');
			}
		} catch (Exception& e) {
			e.printStackTrace();
		}
		iffStream->closeForm('HPTS');

		iffStream->openForm('FLOR');
		iffStream->openChunk('DATA');
		bool hasFloor = iffStream->getByte();
		if (hasFloor)
			iffStream->getString(floorName);
		iffStream->closeChunk('DATA');
		iffStream->closeForm('FLOR');

		iffStream->closeForm('0003');
	} else {
		String msg = "AppearanceTemplate::readObject unknown version (" + String::hexvalueOf((int64)formType) + ")";
		throw Exception(msg);
	}
	iffStream->closeForm('APPR');
}

AppearanceTemplate::~AppearanceTemplate() {
	delete volume;
	delete collisionVolume;
}