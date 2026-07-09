#include "RemoveFriendCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

RemoveFriendCommand::RemoveFriendCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RemoveFriendCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	Reference<PlayerObject*> ghost = creature->getSlottedObject("ghost").castTo<PlayerObject*>();
	ghost->removeFriend(arguments.toString());

	return SUCCESS;
}