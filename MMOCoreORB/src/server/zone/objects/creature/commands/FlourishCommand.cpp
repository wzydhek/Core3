#include "FlourishCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

FlourishCommand::FlourishCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int FlourishCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<EntertainingSession*> session = creature->getActiveSession(SessionFacadeType::ENTERTAINING).castTo<EntertainingSession*>();

	if (session == nullptr || (!session->isDancing() && !session->isPlayingMusic())) {
		creature->sendSystemMessage("@performance:flourish_not_performing");
		return GENERALERROR;
	}

	String args = arguments.toString();

	int index = Integer::valueOf(args);

	if (index < 1 || index > 8) {
		creature->sendSystemMessage("@performance:flourish_not_valid"); // That is not a valid flourish.
		return GENERALERROR;
	}

	Reference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return GENERALERROR;

	String fullString = String("flourish") + "+" + args;

	if (!ghost->hasAbility(fullString)) {
		creature->sendSystemMessage("@performance:flourish_not_valid"); // 	That is not a valid flourish.
		return GENERALERROR;
	}

	session->doFlourish(index, true);

	return SUCCESS;
}

float FlourishCommand::getCommandDuration(CreatureObject* creature, const UnicodeString& arguments) const {
	ManagedReference<EntertainingSession*> session = creature->getActiveSession(SessionFacadeType::ENTERTAINING).castTo<EntertainingSession*>();

	if (session == nullptr)
		return 0.0f;

	int knowledgeSkillMod = 0;
	if (session->isPlayingMusic()) {
		knowledgeSkillMod = creature->getSkillMod("healing_music_ability");
	} else if (session->isDancing()) {
		knowledgeSkillMod = creature->getSkillMod("healing_dance_ability");
	} else {
		return 0.0f;
	}

	// calculating cooldown as defaultTime(5s) - 1s per 30 skill mod val
	// gives a minimum time of 2s at master
	float duration = defaultTime - (knowledgeSkillMod / 30.0f);
	return duration;
}