#include "MarketCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/auction/AuctionManager.h"

int MarketCommand::executeCommand(CreatureObject* creature, uint64 target, const UnicodeString& arguments) {
	if (!creature->isPlayerCreature())
		return 1;

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr || ghost->getAdminLevel() < 15) {
		return 1;
	}

	ManagedReference<AuctionManager*> auctionManager = creature->getZoneServer()->getAuctionManager();
	// Parse the weather command.

	StringTokenizer tokenizer(arguments.toString());
	if (!tokenizer.hasMoreTokens()) {
		sendSyntax(creature);
		return 1;
	}

	String command;
	tokenizer.getStringToken(command);
	command = command.toLowerCase();

	if (command == "enable") {
		auctionManager->setMarketEnabled(true);
		creature->sendSystemMessage("Market Enabled");
	} else if (command == "disable") {
		auctionManager->setMarketEnabled(false);
		creature->sendSystemMessage("Market Disabled");
	} else if (command == "info") {
		auctionManager->displayInfo(creature);
	}

	return 0;
}

void MarketCommand::sendSyntax(CreatureObject* player) {
	if (player != nullptr)
		player->sendSystemMessage("Syntax: /server market [enable/disable/info]");
}