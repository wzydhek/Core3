#include "CreateMissionElementCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/mission/MissionManager.h"

CreateMissionElementCommand::CreateMissionElementCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CreateMissionElementCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature)) {
		return INVALIDLOCOMOTION;
	}

	if (!creature->isPlayerCreature()) {
		return GENERALERROR;
	}

	Reference<PlayerObject*> ghost = creature->getPlayerObject();
	if (ghost == nullptr || !ghost->isPrivileged()) {
		return GENERALERROR;
	}

	// Try to create a mission NPC spawn point.
	creature->getZoneServer()->getMissionManager()->createSpawnPoint(creature, arguments.toString());

	return SUCCESS;
}