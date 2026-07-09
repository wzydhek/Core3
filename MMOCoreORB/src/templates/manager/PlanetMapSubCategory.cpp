#include "PlanetMapSubCategory.h"

PlanetMapSubCategory::PlanetMapSubCategory() {
	name = "";
	nameCRC = 0;
	index = 0;

	activatable = false;
	factionVisibleOnly = false;
}

PlanetMapSubCategory::PlanetMapSubCategory(const PlanetMapSubCategory& pmc) : Object() {
	name = pmc.name;
	nameCRC = pmc.nameCRC;
	index = pmc.index;

	activatable = pmc.activatable;
	faction = pmc.faction;
	factionVisibleOnly = pmc.factionVisibleOnly;
}

PlanetMapSubCategory& PlanetMapSubCategory::operator=(const PlanetMapSubCategory& pmc) {
	if (this == &pmc)
		return *this;

	name = pmc.name;
	nameCRC = pmc.nameCRC;
	index = pmc.index;

	activatable = pmc.activatable;
	faction = pmc.faction;
	factionVisibleOnly = pmc.factionVisibleOnly;

	return *this;
}

PlanetMapSubCategory::~PlanetMapSubCategory() {
}

int PlanetMapSubCategory::compareTo(const PlanetMapSubCategory& pmc) const {
	return name.compareTo(pmc.name);
}

void PlanetMapSubCategory::parseFromDataTableRow(const DataTableRow* row) {
	try {
		bool subCheck = false;
		row->getValue(3, subCheck);

		// These should only be sub categories
		if (!subCheck)
			return;

		row->getValue(0, name);
		nameCRC = name.hashCode();
		row->getValue(1, index);
		// row->getValue(2, category);
		// row->getValue(3, subCategory);
		row->getValue(4, activatable);
		row->getValue(5, faction);
		row->getValue(6, factionVisibleOnly);

	} catch (const Exception& ex) {
		System::out << "Error parsing PlanetMapSubCategory: " + ex.getMessage() << endl;
	}
}

const String& PlanetMapSubCategory::getName() const {
	return name;
}

int PlanetMapSubCategory::getCrc() const {
	return nameCRC;
}

int PlanetMapSubCategory::getIndex() const {
	return index;
}

bool PlanetMapSubCategory::canBeActive() const {
	return activatable;
}

const String& PlanetMapSubCategory::getFaction() const {
	return faction;
}

bool PlanetMapSubCategory::isFactionVisibleOnly() const {
	return factionVisibleOnly;
}