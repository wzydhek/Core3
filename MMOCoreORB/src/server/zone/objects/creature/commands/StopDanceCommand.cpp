#include "StopDanceCommand.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

StopDanceCommand::StopDanceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int StopDanceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<Facade*> facade = creature->getActiveSession(SessionFacadeType::ENTERTAINING);
	ManagedReference<EntertainingSession*> session = dynamic_cast<EntertainingSession*>(facade.get());

	if (session == nullptr || !session->isDancing()) {
		creature->sendSystemMessage("@performance:dance_not_performing"); // You are not currently dancing.
		return GENERALERROR;
	}

	session->stopDancing();

	return SUCCESS;
}