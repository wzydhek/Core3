#include "AnonCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

AnonCommand::AnonCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int AnonCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	PlayerObject* ghost = creature->getPlayerObject();

	if (ghost != nullptr)
		ghost->toggleCharacterBit(PlayerBitmasks::ANONYMOUS);

	return SUCCESS;
}