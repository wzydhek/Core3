/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

/**
 * \file DraftSchematicGroup.h
 * \author Kyle Burkhardt
 * \date 6-01-10
 */

#pragma once

#include "server/zone/objects/draftschematic/DraftSchematic.h"

class DraftSchematicGroup : public Vector<ManagedReference<DraftSchematic*> > {

public:
	DraftSchematicGroup();

	~DraftSchematicGroup();

	bool contains(DraftSchematic* schematic);

	void print();
};
