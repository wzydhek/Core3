/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class ManufactureSchematicObjectDeltaMessage6 : public DeltaMessage {
public:
	ManufactureSchematicObjectDeltaMessage6(SceneObject* schematic);
	
	void insertToResourceSlot(int slotNumber);
};
