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

namespace server {
namespace zone {
namespace managers {
namespace crafting {
namespace schematicmap {

class DraftSchematicGroup : public Vector<ManagedReference<DraftSchematic*> > {

public:
	DraftSchematicGroup();

	~DraftSchematicGroup();

	bool contains(DraftSchematic* schematic);

	void print();
};

} // namespace schematicmap
} // namespace crafting
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::crafting::schematicmap;
