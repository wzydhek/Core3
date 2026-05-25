/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/DeltaMessage.h"

class ManufactureSchematicObjectDeltaMessage6 : public DeltaMessage {
public:
	ManufactureSchematicObjectDeltaMessage6(SceneObject* schematic)
			: DeltaMessage(schematic->getObjectID(), 0x4D53434F, 6) {
	}
	
	void insertToResourceSlot(int slotNumber){
		addByteUpdate(5, slotNumber);
	}
};
