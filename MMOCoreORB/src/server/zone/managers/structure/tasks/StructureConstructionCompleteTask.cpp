#include "StructureConstructionCompleteTask.h"

StructureConstructionCompleteTask::StructureConstructionCompleteTask(CreatureObject* creature) : Task() {
	creatureObject = creature;
}

void StructureConstructionCompleteTask::run() {
	ManagedReference<CreatureObject*> creature = creatureObject.get();

	if (creature == nullptr)
		return;

	Locker lock(creature);

	ManagedReference<PlaceStructureSession*> session = creature->getActiveSession(SessionFacadeType::PLACESTRUCTURE).castTo<PlaceStructureSession*>();

	if (session == nullptr)
		return;

	session->completeSession();
}