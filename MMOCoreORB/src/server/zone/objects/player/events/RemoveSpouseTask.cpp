#include "RemoveSpouseTask.h"

RemoveSpouseTask::RemoveSpouseTask(CreatureObject* creatureObject) : Task() {
	creature = creatureObject;
}

void RemoveSpouseTask::run() {
	if (creature == nullptr)
		return;

	Locker locker(creature);

	PlayerObject* ghost = creature->getPlayerObject().get();
	if (ghost == nullptr)
		return;

	ghost->removeSpouse();
}