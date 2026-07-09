#include "BetCommand.h"
#include "server/zone/objects/tangible/terminal/gambling/GamblingTerminal.h"
#include "server/zone/managers/minigames/GamblingManager.h"

BetCommand::BetCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int BetCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (creature->isPlayerCreature()) {
		CreatureObject* player = cast<CreatureObject*>(creature);

		if (player == nullptr)
			return GENERALERROR;

		GamblingManager* gamblingManager = server->getGamblingManager();

		if (gamblingManager == nullptr)
			return GENERALERROR;

		if (!gamblingManager->isPlaying(player) || !gamblingManager->bettingAllowed(player)) {
			player->sendSystemMessage("@gambling/default_interface:bet_failed");
			return GENERALERROR;
		}

		try {
			StringTokenizer args(arguments.toString());

			if (args.hasMoreTokens()) {
				int amount = args.getIntToken();
				String bet;
				args.getStringToken(bet);

				bet.toLowerCase();

				int targetBet = -1;

				for (int i = 0; i < gamblingManager->getRoulette()->size(); ++i) {
					if (gamblingManager->getRoulette()->get(i) == bet) {
						targetBet = i;
					}
				}

				if (targetBet == -1) {
					player->sendSystemMessage("@gambling/default_interface:bet_failed_amt");
					return GENERALERROR;
				}

				gamblingManager->bet(player, amount, targetBet, 0);
			}
		} catch (Exception& e) {
			player->sendSystemMessage("@gambling/default_interface:bet_failed_amt");
		}
	}

	return SUCCESS;
}