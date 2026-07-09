#include "ClearDefenderListsTask.h"

ClearDefenderListsTask::ClearDefenderListsTask(const DeltaVector<ManagedReference<SceneObject*>>& list, TangibleObject* tano) : defenderList(list), tangibleObject(tano) {
}

void ClearDefenderListsTask::run() {
	Locker locker(tangibleObject);

	for (int i = 0; i < defenderList.size(); ++i) {
		SceneObject* defender = defenderList.get(i);

		if (defender == nullptr || !defender->isTangibleObject())
			continue;

		Locker clocker(defender, tangibleObject);

		(cast<TangibleObject*>(defender))->removeDefender(tangibleObject);
	}

	tangibleObject->removeDefenders();
}