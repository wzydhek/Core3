#include "NewbiehelperCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

NewbiehelperCommand::NewbiehelperCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int NewbiehelperCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	Reference<PlayerObject*> ghost = creature->getSlottedObject("ghost").castTo<PlayerObject*>();

	if (ghost != nullptr)
		ghost->toggleCharacterBit(PlayerBitmasks::NEWBIEHELPER);

	return SUCCESS;
}