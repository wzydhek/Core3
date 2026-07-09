
#pragma once

#include "server/zone/objects/structure/StructureObject.h"

class StructureSetOwnerTask : public Task {
	ManagedReference<StructureObject*> structure;
	uint64 newOwnerID;

public:
	StructureSetOwnerTask(StructureObject* structureObject, uint64 newID);

	void run();
};
