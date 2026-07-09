#include "SarlaccEruptTask.h"

SarlaccEruptTask::SarlaccEruptTask(SarlaccArea* area) {
	sarlaccArea = area;
}

void SarlaccEruptTask::run() {
	if (sarlaccArea == nullptr)
		return;

	Zone* zone = sarlaccArea->getZone();

	if (zone == nullptr)
		return;

	Vector3 worldPos = sarlaccArea->getWorldPosition();

	Reference<SortedVector<ManagedReference<TreeEntry*>>*> closeObjects = new SortedVector<ManagedReference<TreeEntry*>>();
	zone->getInRangeObjects(worldPos.getX(), worldPos.getZ(), worldPos.getY(), 60, closeObjects, true);

	for (int i = 0; i < closeObjects->size(); ++i) {
		SceneObject* scno = cast<SceneObject*>(closeObjects->get(i).get());

		if (scno != nullptr && scno->isPlayerCreature()) {
			ManagedReference<CreatureObject*> playerCreature = cast<CreatureObject*>(scno);

			if (playerCreature == nullptr)
				continue;

			Locker locker(playerCreature);

			playerCreature->sendSystemMessage("@mob/sarlacc:sarlacc_erupt"); // The Sarlacc suddenly erupts, spewing a diseased and corrosive substance into the air!

			if (playerCreature->getSkillMod("resistance_disease") < 24) {
				playerCreature->addDotState(playerCreature, CreatureState::DISEASED, 0, 30 + System::random(20), CreatureAttribute::HEALTH, 30 * 60, 2000, 0);
				playerCreature->sendSystemMessage("@mob/sarlacc:sarlacc_dot"); // You suddenly feel weak and sick.
			}
		}
	}
}