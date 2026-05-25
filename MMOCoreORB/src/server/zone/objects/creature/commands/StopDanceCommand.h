/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

class StopDanceCommand : public QueueCommand {
public:

	StopDanceCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

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

};
