/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

class ManufactureSchematicObjectDeltaMessage3 : public DeltaMessage {
public:
	ManufactureSchematicObjectDeltaMessage3(SceneObject* schematic);

	void updateComplexity(float complexity);

	void updateName(String name);

	void updateCondition(int condition);

	void updateManufactureLimit(int limit);

	void updateCraftingValues(ManufactureSchematic* manufactureSchematic);
};
