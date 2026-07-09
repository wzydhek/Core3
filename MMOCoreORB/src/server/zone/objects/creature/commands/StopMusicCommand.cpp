#include "StopMusicCommand.h"
#include "server/zone/managers/skill/SkillManager.h"
#include "server/zone/managers/skill/PerformanceManager.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

StopMusicCommand::StopMusicCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int StopMusicCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	PerformanceManager* performanceManager = SkillManager::instance()->getPerformanceManager();

	ManagedReference<EntertainingSession*> session = creature->getActiveSession(SessionFacadeType::ENTERTAINING).castTo<EntertainingSession*>();

	if (session == nullptr || !session->isPlayingMusic()) {
		performanceManager->performanceMessageToSelf(creature, nullptr, "performance", "music_not_performing"); // You are not currently playing a song.
		return GENERALERROR;
	}

	session->stopMusic(false);

	return SUCCESS;
}