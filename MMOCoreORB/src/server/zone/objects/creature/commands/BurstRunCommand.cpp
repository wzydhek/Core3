#include "BurstRunCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"

BurstRunCommand::BurstRunCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int BurstRunCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		if (creature->isRidingMount()) {
			creature->sendSystemMessage("@cbt_spam:no_burst");
		}
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();

	if (!playerManager->doBurstRun(creature, 0.f, 0.f))
		return GENERALERROR;

	return SUCCESS;
}