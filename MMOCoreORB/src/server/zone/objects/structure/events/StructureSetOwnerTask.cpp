#include "StructureSetOwnerTask.h"

StructureSetOwnerTask::StructureSetOwnerTask(StructureObject* structureObject, uint64 newID) : Task() {
	structure = structureObject;
	newOwnerID = newID;
}

void StructureSetOwnerTask::run() {
	if (structure == nullptr)
		return;

	Locker locker(structure);

	structure->setOwner(newOwnerID);
}