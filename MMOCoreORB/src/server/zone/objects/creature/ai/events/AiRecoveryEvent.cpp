#include "AiRecoveryEvent.h"

AiRecoveryEvent::AiRecoveryEvent(AiAgent* aiAgent) : Task(1000) {
	agent = aiAgent;
	startTime.updateToCurrentTime();
	AiMap::instance()->activeRecoveryEvents.increment();
}

AiRecoveryEvent::~AiRecoveryEvent() {
	AiMap::instance()->activeRecoveryEvents.decrement();
}

void AiRecoveryEvent::run() {
	ManagedReference<AiAgent*> strongRef = agent.get();

	if (strongRef == nullptr || (!strongRef->isPet() && (strongRef->isDead() || strongRef->isIncapacitated())))
		return;

	ZoneServer* zoneServer = strongRef->getZoneServer();

	if (zoneServer != nullptr && zoneServer->isServerShuttingDown())
		return;

	Locker locker(strongRef);
	strongRef->doRecovery(startTime.miliDifference());
}

void AiRecoveryEvent::schedule(uint64 delay) {
	startTime.updateToCurrentTime();
	Task::schedule(delay);
}

void AiRecoveryEvent::clearAgentObject() {
	agent = nullptr;
}