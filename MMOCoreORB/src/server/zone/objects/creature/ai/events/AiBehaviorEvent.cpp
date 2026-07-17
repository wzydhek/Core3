#include "AiBehaviorEvent.h"

AiBehaviorEvent::AiBehaviorEvent(AiAgent* pl) : Task(1000), creature(pl), hasFollowObject(false), isRetreating(false) {
	AiMap::instance()->activeBehaviorEvents.increment();
}

AiBehaviorEvent::~AiBehaviorEvent() {
	AiMap::instance()->activeBehaviorEvents.decrement();

	if (hasFollowObject) {
		AiMap::instance()->behaviorsWithFollowObject.decrement();

		hasFollowObject = false;
	}

	if (isRetreating) {
		AiMap::instance()->behaviorsRetreating.decrement();

		isRetreating = false;
	}
}

void AiBehaviorEvent::run() {
	AiMap::instance()->scheduledBehaviorEvents.decrement();

	if (hasFollowObject) {
		AiMap::instance()->behaviorsWithFollowObject.decrement();

		hasFollowObject = false;
	}

	if (isRetreating) {
		AiMap::instance()->behaviorsRetreating.decrement();

		isRetreating = false;
	}

	ManagedReference<AiAgent*> strongRef = creature.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	strongRef->runBehaviorTree();
}

void AiBehaviorEvent::schedule(uint64 delay) {
	AiMap::instance()->scheduledBehaviorEvents.increment();

	ManagedReference<AiAgent*> strongRef = creature.get();

	if (strongRef != nullptr) {
		auto zone = strongRef->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);

		if (strongRef != nullptr) {
			if (strongRef->getFollowObject() != nullptr && !hasFollowObject) {
				AiMap::instance()->behaviorsWithFollowObject.increment();

				hasFollowObject = true;
			} else if (strongRef->getFollowObject() == nullptr && hasFollowObject) {
				AiMap::instance()->behaviorsWithFollowObject.decrement();

				hasFollowObject = false;
			}

			if (strongRef->isRetreating() && !isRetreating) {
				AiMap::instance()->behaviorsRetreating.increment();

				isRetreating = true;
			} else if (!strongRef->isRetreating() && isRetreating) {
				AiMap::instance()->behaviorsRetreating.decrement();

				isRetreating = false;
			}
		}
	} catch (...) {
		AiMap::instance()->scheduledBehaviorEvents.decrement();
	}
}

bool AiBehaviorEvent::cancel() {
	bool ret = false;

	if ((ret = Task::cancel())) {
		AiMap::instance()->scheduledBehaviorEvents.decrement();

		if (hasFollowObject) {
			AiMap::instance()->behaviorsWithFollowObject.decrement();

			hasFollowObject = false;
		}

		if (isRetreating) {
			AiMap::instance()->behaviorsRetreating.decrement();

			isRetreating = false;
		}
	}

	return ret;
}

void AiBehaviorEvent::clearCreatureObject() {
	creature = nullptr;
}