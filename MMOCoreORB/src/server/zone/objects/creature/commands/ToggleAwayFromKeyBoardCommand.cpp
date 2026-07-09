#include "ToggleAwayFromKeyBoardCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

ToggleAwayFromKeyBoardCommand::ToggleAwayFromKeyBoardCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ToggleAwayFromKeyBoardCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	Reference<PlayerObject*> ghost = creature->getSlottedObject("ghost").castTo<PlayerObject*>();

	if (ghost != nullptr)
		ghost->toggleCharacterBit(PlayerBitmasks::AFK);

	return SUCCESS;
}