#include "InstallationObjectDeltaMessage3.h"

InstallationObjectDeltaMessage3::InstallationObjectDeltaMessage3(InstallationObject* ins) : TangibleObjectDeltaMessage3(ins, 0x494E534F) {
	inso = ins;
}

void InstallationObjectDeltaMessage3::updateOperating(bool value) {
	/*if (value)
		addIntUpdate(0x06, 0x00000101); // 01 01 00 00
	else
		addIntUpdate(0x06, 0x00000100); // 00 01 00 00*/
	addByteUpdate(0x0B, value);
}