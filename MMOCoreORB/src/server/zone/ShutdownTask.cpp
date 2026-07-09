#include "ShutdownTask.h"
#include "server/zone/objects/creature/CreatureObject.h"

ShutdownTask::ShutdownTask(ZoneServer* srv, int minutes, int flags) {
	zoneServer = srv;
	minutesRemaining = minutes;
	shutdownFlags = flags;
}

void ShutdownTask::run() {
	--minutesRemaining;

	StringBuffer shutdownMsg;

	if (minutesRemaining <= 0) {
		shutdownMsg << "You will now be disconnected so the server can perform a final save before shutting down.";
	} else {
		shutdownMsg << "You will be disconnected in ";

		if (minutesRemaining > 1) {
			shutdownMsg << minutesRemaining << " minutes ";
		} else {
			shutdownMsg << minutesRemaining << " minute ";
		}

		shutdownMsg << "so the server can perform a final save before shutting down. Please find a safe place to logout.";
	}

	Logger::console.info(true) << shutdownMsg.toString();

	zoneServer->getChatManager()->broadcastGalaxy(nullptr, shutdownMsg.toString());

	if (minutesRemaining <= 0) {
		ServerCore::getInstance()->signalShutdown(static_cast<ServerCore::ShutdownFlags>(shutdownFlags));
	} else {
		schedule(60 * 1000);
	}
}