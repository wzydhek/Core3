#include "SetSteadyaimCommand.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/objects/player/PlayerObject.h"

SetSteadyaimCommand::SetSteadyaimCommand(const String& name, ZoneProcessServer* server) : SquadLeaderCommand(name, server) {
}

int SetSteadyaimCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->hasSkill("outdoors_squadleader_offense_01")) {
		//			StringIdChatParameter params("@error_message:prose_nsf_skill_cmd"); //You lack sufficient skill to use the %TO command.
		//			params.setTO("@skl_n:" + skill->getSkillName());
		creature->sendSystemMessage("You lack sufficient skill to use the SetSteadyaim command."); // SetSteadyaim isn't a skill...
		return GENERALERROR;
	}

	ManagedReference<CreatureObject*> player = (creature);
	ManagedReference<PlayerObject*> playerObject = player->getPlayerObject();

	String message = arguments.toString();

	if (message.length() > 128) {
		player->sendSystemMessage("Your Steadyaim message can only be up to 128 characters long.");
		return false;
	}

	ZoneProcessServer* zps = player->getZoneProcessServer();
	NameManager* nameManager = zps->getNameManager();

	if (nameManager->isProfane(message)) {
		player->sendSystemMessage("Your Steadyaim message has failed the profanity filter.");
		return false;
	}

	if (message.isEmpty()) {
		playerObject->removeCommandMessageString(STRING_HASHCODE("steadyaim"));
		player->sendSystemMessage("Your Steadyaim message has been removed.");
	} else {
		playerObject->setCommandMessageString(STRING_HASHCODE("steadyaim"), message);
		player->sendSystemMessage("Your Steadyaim message was set to :-\n" + message);
	}

	return SUCCESS;
}