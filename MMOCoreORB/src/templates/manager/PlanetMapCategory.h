/*
 * PlanetMapCategory.h
 *
 *  Created on: Apr 24, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

class PlanetMapCategory : public Object {
	String name;
	int nameCRC;
	int index;

	bool activatable;
	String faction;
	bool factionVisibleOnly;

public:
	PlanetMapCategory();

	PlanetMapCategory(const PlanetMapCategory& pmc);

	PlanetMapCategory& operator=(const PlanetMapCategory& pmc);

	~PlanetMapCategory();

	int compareTo(const PlanetMapCategory& pmc) const;

	void parseFromDataTableRow(const DataTableRow* row);

	const String& getName() const;

	int getCrc() const;

	int getIndex() const;

	bool canBeActive() const;

	const String& getFaction() const;

	bool isFactionVisibleOnly() const;

};
