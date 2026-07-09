#include "OnlinePlayerLogTask.h"

OnlinePlayerLogTask::OnlinePlayerLogTask() : Task() {
}

void OnlinePlayerLogTask::run() {
	auto server = ServerCore::getZoneServer();

	if (server == nullptr)
		return;

	Reference<PlayerManager*> playerManager = server->getPlayerManager();

	if (playerManager == nullptr)
		return;

	playerManager->logOnlinePlayers(false);
}