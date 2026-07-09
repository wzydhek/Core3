#include "ServerStatisticsCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/statistics/StatisticsManager.h"

int ServerStatisticsCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost == nullptr || ghost->getAdminLevel() < 15)
		return 1;

	StringTokenizer args(arguments.toString());

	if (args.hasMoreTokens()) {
		String command;
		args.getStringToken(command);

		if (command.toLowerCase() == "reset") {
			StatisticsManager::instance()->reset();
			creature->sendSystemMessage("Statistics have been reset.");
		}
	} else {
		creature->sendSystemMessage(StatisticsManager::instance()->getStatistics());
	}

	return 0;
}

void ServerStatisticsCommand::sendSyntax(CreatureObject* player) {
	if (player != nullptr)
		player->sendSystemMessage("Syntax: /server statistics");
}