/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "templates/customization/CustomizationVariable.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

class ManufactureSchematicObjectDeltaMessage7 : public DeltaMessage, public Logger {
public:
	ManufactureSchematicObjectDeltaMessage7(SceneObject* schematic);

	void updateForAssembly(ManufactureSchematic* manufactureSchematic, float failureRate);

	void updateCustomizationOptions(VectorMap<String, Reference<CustomizationVariable*>>* vars, int custpoints);

	// update 8
	void initialAssemblyUpdate(ManufactureSchematic* manufactureSchematic);

	// This sends the experimental values shown in the Screen after hitting assemble
	void update9(ManufactureSchematic* manufactureSchematic, bool initial);

	void update0A(ManufactureSchematic* manufactureSchematic);

	// I think this is usually 1.0
	void update0B(ManufactureSchematic* manufactureSchematic);

	// This is the MAX experimental value.  How many bars
	void update0C(ManufactureSchematic* manufactureSchematic);

	void update0D(VectorMap<String, Reference<CustomizationVariable*>>* vars);

	// Starting COlor chooser position
	void update0E(VectorMap<String, Reference<CustomizationVariable*>>* vars);

	void update0F(VectorMap<String, Reference<CustomizationVariable*>>* vars);

	// Number of palette colors
	void update10(VectorMap<String, Reference<CustomizationVariable*>>* vars, int custpoints);

	void update11();

	void update12(float failureRate);

	void update13(ManufactureSchematic* manufactureSchematic);

	void update14();

};
