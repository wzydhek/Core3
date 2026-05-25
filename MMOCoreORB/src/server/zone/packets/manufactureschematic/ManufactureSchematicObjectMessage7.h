/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

class ManufactureSchematicObjectMessage7: public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage7(SceneObject* schematic) :
			BaseLineMessage(schematic->getObjectID(), 0x4D53434F, 7, 0x15) {

	}

};
