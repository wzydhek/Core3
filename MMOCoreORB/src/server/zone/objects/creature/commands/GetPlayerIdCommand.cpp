#include "GetPlayerIdCommand.h"
#include "server/zone/managers/player/PlayerManager.h"

GetPlayerIdCommand::GetPlayerIdCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GetPlayerIdCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<CreatureObject*> targetCreature = nullptr;

	StringTokenizer args(arguments.toString());

	if (args.hasMoreTokens()) {
		String character;
		args.getStringToken(character);

		ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();
		targetCreature = playerManager->getPlayer(character);

	} else {
		targetCreature = server->getZoneServer()->getObject(target).castTo<CreatureObject*>();
	}

	if (targetCreature == nullptr || !targetCreature->isPlayerCreature())
		return INVALIDTARGET;

	creature->sendSystemMessage("PlayerId for " + targetCreature->getFirstName() + ": " + String::valueOf(targetCreature->getObjectID()));

	return SUCCESS;
}