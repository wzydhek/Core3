#include "ServerInfoCommand.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/ZoneServer.h"
#include "BoardShuttleCommand.h"

int ServerInfoCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return 1;

	ZoneServer* zserv = creature->getZoneServer();

	SuiMessageBox* box = new SuiMessageBox(creature, 0);
	box->setPromptTitle("Server Information");
	box->setPromptText(zserv->getInfo());

	ghost->addSuiBox(box);
	creature->sendMessage(box->generateMessage());

	StringTokenizer tokenizer(arguments.toString());

	if (tokenizer.hasMoreTokens()) {
		try {
			int cityCap = tokenizer.getIntToken();

			BoardShuttleCommand::MAXIMUM_PLAYER_COUNT = cityCap;

			creature->sendSystemMessage("Maximum number of player per city set to " + String::valueOf(cityCap));
		} catch (...) {
			creature->error("exception parsing city cap");
		}
	}

	return 0;
}

void ServerInfoCommand::sendSyntax(CreatureObject* player) {
	if (player != nullptr)
		player->sendSystemMessage("Syntax: /server info");
}