#include "ShipAiBehaviorEvent.h"

ShipAiBehaviorEvent::ShipAiBehaviorEvent(ShipAiAgent* pl) : Task(1000), agent(pl), hasFollowObject(false), isRetreating(false) {
	SpaceAiMap::instance()->activeBehaviorEvents.increment();
}

ShipAiBehaviorEvent::~ShipAiBehaviorEvent() {
	SpaceAiMap::instance()->activeBehaviorEvents.decrement();

	if (hasFollowObject) {
		SpaceAiMap::instance()->behaviorsWithFollowObject.decrement();

		hasFollowObject = false;
	}

	if (isRetreating) {
		SpaceAiMap::instance()->behaviorsRetreating.decrement();

		isRetreating = false;
	}
}

void ShipAiBehaviorEvent::run() {
	SpaceAiMap::instance()->scheduledBehaviorEvents.decrement();

	if (hasFollowObject) {
		SpaceAiMap::instance()->behaviorsWithFollowObject.decrement();

		hasFollowObject = false;
	}

	if (isRetreating) {
		SpaceAiMap::instance()->behaviorsRetreating.decrement();

		isRetreating = false;
	}

	ManagedReference<ShipAiAgent*> strongRef = agent.get();

	if (strongRef == nullptr)
		return;

	Locker locker(strongRef);

	strongRef->runBehaviorTree();

	// strongRef->info(true) << strongRef->getDisplayedName() << " - ID: " << strongRef->getObjectID() << " -- ShipAiBehaviorEvent ran";
}

void ShipAiBehaviorEvent::schedule(uint64 delay) {
	SpaceAiMap::instance()->scheduledBehaviorEvents.increment();

	ManagedReference<ShipAiAgent*> strongRef = agent.get();

	if (strongRef != nullptr) {
		auto zone = strongRef->getZone();

		if (zone != nullptr) {
			setCustomTaskQueue(zone->getZoneName());
		}
	}

	try {
		Task::schedule(delay);

		if (strongRef != nullptr) {
			// strongRef->info(true) << strongRef->getDisplayedName() << " - ID: " << strongRef->getObjectID() << " -- ShipAiBehavior scheduled with delay: " << delay;

			if (strongRef->getFollowShipObject().get() != nullptr && !hasFollowObject) {
				SpaceAiMap::instance()->behaviorsWithFollowObject.increment();

				hasFollowObject = true;
			} else if (strongRef->getFollowShipObject().get() == nullptr && hasFollowObject) {
				SpaceAiMap::instance()->behaviorsWithFollowObject.decrement();

				hasFollowObject = false;
			}

			if (strongRef->isRetreating() && !isRetreating) {
				SpaceAiMap::instance()->behaviorsRetreating.increment();

				isRetreating = true;
			} else if (!strongRef->isRetreating() && isRetreating) {
				SpaceAiMap::instance()->behaviorsRetreating.decrement();

				isRetreating = false;
			}
		}
	} catch (...) {
		SpaceAiMap::instance()->scheduledBehaviorEvents.decrement();
	}
}

bool ShipAiBehaviorEvent::cancel() {
	bool ret = false;

	if ((ret = Task::cancel())) {
		SpaceAiMap::instance()->scheduledBehaviorEvents.decrement();

		if (hasFollowObject) {
			SpaceAiMap::instance()->behaviorsWithFollowObject.decrement();

			hasFollowObject = false;
		}

		if (isRetreating) {
			SpaceAiMap::instance()->behaviorsRetreating.decrement();

			isRetreating = false;
		}
	}

	return ret;
}

void ShipAiBehaviorEvent::clearShipAgentObject() {
	agent = nullptr;
}