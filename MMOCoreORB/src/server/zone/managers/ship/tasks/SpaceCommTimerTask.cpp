#include "SpaceCommTimerTask.h"

SpaceCommTimerTask::SpaceCommTimerTask(CreatureObject* playerCreo, uint64 oid) : Task() {
	play = playerCreo;
	shipID = oid;

	Logger::setLoggingName("SpaceCommTimerTask");
}

void SpaceCommTimerTask::run() {
	auto player = play.get();

	if (player == nullptr) {
		return;
	}

	ZoneServer* zoneServer = player->getZoneServer();

	if (zoneServer != nullptr && zoneServer->isServerShuttingDown()) {
		cancel();
		return;
	}

	player->sendExecuteConsoleCommand("/conversationstop");
}