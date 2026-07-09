#include "DazzleCommand.h"
#include "server/zone/managers/skill/PerformEffect.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

DazzleCommand::DazzleCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DazzleCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<EntertainingSession*> session = creature->getActiveSession(SessionFacadeType::ENTERTAINING).castTo<EntertainingSession*>();

	if (session == nullptr || (!session->isPlayingMusic() && !session->isDancing())) {
		creature->sendSystemMessage("@performance:effect_not_performing"); // You must be performing in order to execute this special effect.
		return GENERALERROR;
	}

	int effectLevel = Integer::valueOf(arguments.toString());
	session->doPerformEffect(PerformEffect::DAZZLE, effectLevel);

	return SUCCESS;
}