#include "SetBiographyCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

SetBiographyCommand::SetBiographyCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetBiographyCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	auto ghost = creature->getPlayerObject();

	if (ghost == nullptr) {
		return GENERALERROR;
	}

	ghost->setBiography(arguments);

	return SUCCESS;
}