#include "InnateCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

InnateCommand::InnateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int InnateCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	String innateCommand;

	try {
		UnicodeTokenizer tokenizer(arguments);
		tokenizer.getStringToken(innateCommand);

		innateCommand = innateCommand.toLowerCase();
	} catch (Exception& e) {
		return INVALIDPARAMETERS;
	}

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost != nullptr)
		return GENERALERROR;

	if (!ghost->hasAbility(innateCommand)) {
		StringIdChatParameter stringId;
		stringId.setStringId("@innate:innate_na"); // Innate Command parameter '%TO' is not available for your species.

		if (innateCommand == "vitalize")
			stringId.setTO("@innate:vit"); // vitalize
		else if (innateCommand == "equilibrium")
			stringId.setTO("@innate:equil"); // equilibrium
		else if (innateCommand == "regeneration")
			stringId.setTO("@innate:regen"); // regeneration
		else if (innateCommand == "wookieeroar")
			stringId.setTO("@innate:roar"); // wookiee roar
		else
			return INVALIDPARAMETERS;

		creature->sendSystemMessage(stringId);

		return GENERALERROR;
	}

	creature->executeObjectControllerAction(innateCommand.hashCode());

	return SUCCESS;
}