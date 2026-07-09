#include "RequestCharacterSheetInfoCommand.h"
#include "server/zone/packets/player/CharacterSheetResponseMessage.h"

RequestCharacterSheetInfoCommand::RequestCharacterSheetInfoCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RequestCharacterSheetInfoCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	BaseMessage* message = new CharacterSheetResponseMessage(creature);
	creature->sendMessage(message);

	return SUCCESS;
}