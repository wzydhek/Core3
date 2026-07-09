#include "DraftSchematicGroup.h"

DraftSchematicGroup::DraftSchematicGroup() {
}

DraftSchematicGroup::~DraftSchematicGroup() {
}

bool DraftSchematicGroup::contains(DraftSchematic* schematic) {
	for (int i = 0; i < size(); ++i) {
		DraftSchematic* existingSchematic = get(i);
		if (existingSchematic->getClientObjectCRC() == schematic->getClientObjectCRC())
			return true;
	}
	return false;
}

void DraftSchematicGroup::print() {
	for (int i = 0; i < size(); ++i) {
		System::out << get(i)->getCustomName() << endl;
	}
}