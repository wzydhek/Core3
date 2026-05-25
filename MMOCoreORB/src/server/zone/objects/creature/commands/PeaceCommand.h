/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/managers/combat/CombatManager.h"

class PeaceCommand : public QueueCommand {
public:

	PeaceCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		creature->clearQueueActions(true);

		CombatManager::instance()->attemptPeace(creature);

		return SUCCESS;
	}

};
