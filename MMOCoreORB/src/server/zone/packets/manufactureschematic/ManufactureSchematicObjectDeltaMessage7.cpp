#include "ManufactureSchematicObjectDeltaMessage7.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "templates/params/RangedIntCustomizationVariable.h"

ManufactureSchematicObjectDeltaMessage7::ManufactureSchematicObjectDeltaMessage7(SceneObject* schematic) : DeltaMessage(schematic->getObjectID(), 0x4D53434F, 7) {
	setLoggingName("ManufactureSchematicObjectDeltaMessage7");
}

void ManufactureSchematicObjectDeltaMessage7::updateForAssembly(ManufactureSchematic* manufactureSchematic, float failureRate) {
	initialAssemblyUpdate(manufactureSchematic);
	update9(manufactureSchematic, true);
	// update0A(manufactureSchematic);
	update0B(manufactureSchematic);
	update0C(manufactureSchematic);
	update12(failureRate);
	update13(manufactureSchematic);
}

void ManufactureSchematicObjectDeltaMessage7::updateCustomizationOptions(VectorMap<String, Reference<CustomizationVariable*>>* vars, int custpoints) {
	update0D(vars);
	update0E(vars);
	update0F(vars);
	update10(vars, custpoints);
	update11();
}

// update 8
void ManufactureSchematicObjectDeltaMessage7::initialAssemblyUpdate(ManufactureSchematic* manufactureSchematic) {
	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - initialAssemblyUpdate Update 8";

	startUpdate(0x08);

	int totalGroups = craftingValues->getTotalVisibleAttributeGroups();
	int counter = manufactureSchematic->getExperimentingCounter();

	insertInt(totalGroups);
	insertInt(totalGroups);

	for (int i = 0; i < totalGroups; i++) {
		String title = craftingValues->getVisibleAttributeGroup(i);

		insertByte(1);
		insertShort(i);
		insertAscii("crafting"); // I think this is always "crafting"
		insertInt(0);
		insertAscii(title);
	}

	// Initialize update 9************
	startUpdate(0x09);

	startList(totalGroups, totalGroups); // totalGroups, counter

	for (int i = 0; i < totalGroups; i++) {
		addListFloatElement(i, 0); // 0
	}

	//!*********************************
	// Initialize update 0A************
	startUpdate(0x0A);

	startList(totalGroups, totalGroups);

	for (int i = 0; i < totalGroups; i++) {
		addListFloatElement(i, 0);
	}

	//!*********************************
	// Initialize update 0B************
	startUpdate(0x0B);

	startList(totalGroups, totalGroups);

	for (int i = 0; i < totalGroups; i++) {
		addListFloatElement(i, 0);
	}

	//!*********************************
	// Initialize update 0C************
	startUpdate(0x0C);

	startList(totalGroups, totalGroups);

	for (int i = 0; i < totalGroups; i++) {
		addListFloatElement(i, 0);
	}
	//!**********************************

	// info(true) << "END ManufactureSchematicObjectDeltaMessage7 - initialAssemblyUpdate Update 8";
}

// This sends the experimental values shown in the Screen after hitting assemble
void ManufactureSchematicObjectDeltaMessage7::update9(ManufactureSchematic* manufactureSchematic, bool initial) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - update9";

	int count;

	startUpdate(0x09);

	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	int totalGroups = craftingValues->getTotalVisibleAttributeGroups();

	if (initial) {
		manufactureSchematic->setExperimentingCounter(totalGroups * 2);
		manufactureSchematic->setExperimentingCounter(totalGroups * 3);
	}

	count = manufactureSchematic->getExperimentingCounterPrevious();

	// info(true) << "Visible Groups: " << totalGroups << " Current Count: " << count;

	startList(totalGroups, count);

	for (int i = 0; i < totalGroups; i++) {
		String group = craftingValues->getVisibleAttributeGroup(i);

		float value = craftingValues->getCurrentVisiblePercentage(group);

		if (value > 0 && value < .01)
			value = .01f;

		removeListFloatElement(i, value);
	}
}

void ManufactureSchematicObjectDeltaMessage7::update0A(ManufactureSchematic* manufactureSchematic) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 10 (0A)";

	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	startUpdate(0x0A);

	int totalGroups = craftingValues->getTotalVisibleAttributeGroups();

	startList(totalGroups, totalGroups * 2);

	for (int i = 0; i < totalGroups; i++) {
		removeListFloatElement(i, 1.0f);
	}
}

// I think this is usually 1.0
void ManufactureSchematicObjectDeltaMessage7::update0B(ManufactureSchematic* manufactureSchematic) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 11 (0B)";

	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	startUpdate(0x0B);

	int totalGroups = craftingValues->getTotalVisibleAttributeGroups();

	startList(totalGroups, totalGroups * 2);

	for (int i = 0; i < totalGroups; i++) {
		removeListFloatElement(i, 1.0f);
	}
}
// This is the MAX experimental value.  How many bars
void ManufactureSchematicObjectDeltaMessage7::update0C(ManufactureSchematic* manufactureSchematic) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 12 (0C)";

	CraftingValues* craftingValues = manufactureSchematic->getCraftingValues();

	startUpdate(0x0C);

	int totalGroups = craftingValues->getTotalVisibleAttributeGroups();

	startList(totalGroups, totalGroups * 2);

	float value;

	for (int i = 0; i < totalGroups; i++) {
		value = craftingValues->getMaxVisiblePercentage(i);

		removeListFloatElement(i, value);
	}
}

void ManufactureSchematicObjectDeltaMessage7::update0D(VectorMap<String, Reference<CustomizationVariable*>>* vars) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 13 (0D)";

	startUpdate(0x0D);

	startList(vars->size(), vars->size());

	for (int i = 0; i < vars->size(); ++i) {
		insertByte(0x01);
		insertShort(i);
		RangedIntCustomizationVariable* var = cast<RangedIntCustomizationVariable*>(vars->get(i).get());
		if (var == nullptr)
			insertAscii("");
		else
			insertAscii(vars->elementAt(i).getKey());
	}
}

// Starting COlor chooser position
void ManufactureSchematicObjectDeltaMessage7::update0E(VectorMap<String, Reference<CustomizationVariable*>>* vars) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 14 (0E)";

	startUpdate(0x0E);

	startList(vars->size(), vars->size());

	for (int i = 0; i < vars->size(); ++i) {
		insertByte(0x01);
		insertShort(i);
		RangedIntCustomizationVariable* var = cast<RangedIntCustomizationVariable*>(vars->get(i).get());
		if (var == nullptr)
			insertInt(0);
		else
			insertInt(var->getDefaultValue());
	}
}

void ManufactureSchematicObjectDeltaMessage7::update0F(VectorMap<String, Reference<CustomizationVariable*>>* vars) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 15 (0F)";

	startUpdate(0x0F);

	startList(vars->size(), vars->size());

	for (int i = 0; i < vars->size(); ++i) {
		insertByte(0x01);
		insertShort(i);
		insertInt(0);
	}
}

// Number of palette colors
void ManufactureSchematicObjectDeltaMessage7::update10(VectorMap<String, Reference<CustomizationVariable*>>* vars, int custpoints) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7 - Update 16 (10)";

	startUpdate(0x10);

	startList(vars->size(), vars->size());

	for (int i = 0; i < vars->size(); ++i) {
		insertByte(0x01);
		insertShort(i);
		insertInt(custpoints);
	}
}

void ManufactureSchematicObjectDeltaMessage7::update11() {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7::update11";

	startUpdate(0x11);
	insertByte(1);
}

void ManufactureSchematicObjectDeltaMessage7::update12(float failureRate) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7::update12";

	startUpdate(0x12);
	insertFloat(failureRate);
}

void ManufactureSchematicObjectDeltaMessage7::update13(ManufactureSchematic* manufactureSchematic) {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7::update13";

	ManagedReference<DraftSchematic*> draftSchematic = manufactureSchematic->getDraftSchematic();
	if (draftSchematic == nullptr)
		return;

	startUpdate(0x13);

	/// Template List
	int templateCount = draftSchematic->getTemplateListSize();

	startList(templateCount, templateCount);

	/// The first template is the
	for (int i = 0; i < templateCount; ++i) {
		insertByte(0x01);
		insertShort(i);
		insertAscii(draftSchematic->getTemplate(i));
	}
}

void ManufactureSchematicObjectDeltaMessage7::update14() {
	// info(true) << "ManufactureSchematicObjectDeltaMessage7::update14";

	startUpdate(0x14);
	insertByte(1);
}