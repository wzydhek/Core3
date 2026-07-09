#include "PlanetMapCategory.h"

PlanetMapCategory::PlanetMapCategory() {
	nameCRC = 0;
	index = 0;

	activatable = false;
	factionVisibleOnly = false;
}

PlanetMapCategory::PlanetMapCategory(const PlanetMapCategory& pmc) : Object() {
	name = pmc.name;
	nameCRC = pmc.nameCRC;
	index = pmc.index;

	activatable = pmc.activatable;
	faction = pmc.faction;
	factionVisibleOnly = pmc.factionVisibleOnly;
}

PlanetMapCategory& PlanetMapCategory::operator=(const PlanetMapCategory& pmc) {
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

PlanetMapCategory::~PlanetMapCategory() {
}

int PlanetMapCategory::compareTo(const PlanetMapCategory& pmc) const {
	return name.compareTo(pmc.name);
}

void PlanetMapCategory::parseFromDataTableRow(const DataTableRow* row) {
	try {
		bool primaryCat = false;
		row->getValue(2, primaryCat);

		if (!primaryCat)
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
		System::out << "Error parsing PlanetMapCategory: " + ex.getMessage() << endl;
	}
}

const String& PlanetMapCategory::getName() const {
	return name;
}

int PlanetMapCategory::getCrc() const {
	return nameCRC;
}

int PlanetMapCategory::getIndex() const {
	return index;
}

bool PlanetMapCategory::canBeActive() const {
	return activatable;
}

const String& PlanetMapCategory::getFaction() const {
	return faction;
}

bool PlanetMapCategory::isFactionVisibleOnly() const {
	return factionVisibleOnly;
}