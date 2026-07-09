#include "InstallationObjectDeltaMessage7.h"

InstallationObjectDeltaMessage7::InstallationObjectDeltaMessage7(InstallationObject* ins) : DeltaMessage(ins->getObjectID(), 0x494E534F, 7) {
	inso = ins;
}

void InstallationObjectDeltaMessage7::updateExtractionRate(float rate) {
	addFloatUpdate(0x09, rate);
}

void InstallationObjectDeltaMessage7::setNoHopperUpdate() {
	addByteUpdate(0x0C, 0);
}

void InstallationObjectDeltaMessage7::updateOperating(bool state) {
	addByteUpdate(0x06, state);
}

void InstallationObjectDeltaMessage7::updateHopper() {
	addByteUpdate(0x0C, 1); // think about incrementing like a counter
}

void InstallationObjectDeltaMessage7::updateHopperSize(float size) {
	addFloatUpdate(0x0A, size);
}

void InstallationObjectDeltaMessage7::updateActiveResourceSpawn(uint64 id) {
	addLongUpdate(0x05, id);
}
