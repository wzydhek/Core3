#include "LairRepopulateTask.h"
#include "server/zone/objects/tangible/LairObject.h"

LairRepopulateTask::LairRepopulateTask(TangibleObject* obj, LairObserver* observer) {
	lair = obj;
	this->observer = observer;
}

void LairRepopulateTask::run() {
	TangibleObject* strongLair = lair.get();
	LairObserver* strongObserver = observer.get();

	if (strongLair == nullptr || strongObserver == nullptr) {
		return;
	}

	if (strongLair->isDestroyed() || strongObserver->getLivingCreatureCount() < 1)
		return;

	LairObject* lair = cast<LairObject*>(strongLair);

	if (lair != nullptr && (lair->isRepopulated() || lair->getNumberOfPlayersInRange() > 0))
		return;

	strongObserver->repopulateLair(strongLair);
}