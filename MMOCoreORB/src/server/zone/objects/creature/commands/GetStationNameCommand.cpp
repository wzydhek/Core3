#include "GetStationNameCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/login/account/Account.h"

GetStationNameCommand::GetStationNameCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GetStationNameCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return INVALIDTARGET;

	ManagedReference<CreatureObject*> targetCreature = nullptr;
	ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

	StringTokenizer args(arguments.toString());

	if (args.hasMoreTokens()) {
		String character;
		args.getStringToken(character);

		targetCreature = playerManager->getPlayer(character);

	} else {
		targetCreature = server->getZoneServer()->getObject(target).castTo<CreatureObject*>();
	}

	if (targetCreature == nullptr || !targetCreature->isPlayerCreature())
		return INVALIDTARGET;

	ManagedReference<Account*> account = targetCreature->getPlayerObject()->getAccount();
	if (account == nullptr) {
		creature->sendSystemMessage("Account not found");
		return SUCCESS;
	}

	Locker alocker(account);

	creature->sendSystemMessage("Account name for " + targetCreature->getFirstName() + ": " + account->getUsername());

	return SUCCESS;
}