/*
 * PlanetMapSubCategory.h
 */

#pragma once

#include "templates/datatables/DataTableRow.h"
#include "server/zone/managers/planet/MapLocationType.h"

namespace templates {

class PlanetMapSubCategory : public Object {
	String name;
	int nameCRC;
	int index;

	bool activatable;
	String faction;
	bool factionVisibleOnly;

public:
	PlanetMapSubCategory();

	PlanetMapSubCategory(const PlanetMapSubCategory& pmc);

	PlanetMapSubCategory& operator=(const PlanetMapSubCategory& pmc);

	~PlanetMapSubCategory();

	int compareTo(const PlanetMapSubCategory& pmc) const;

	void parseFromDataTableRow(const DataTableRow* row);

	const String& getName() const;

	int getCrc() const;

	int getIndex() const;

	bool canBeActive() const;

	const String& getFaction() const;

	bool isFactionVisibleOnly() const;
};

} // namespace templates

using namespace templates;
