/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CombatQueueCommand.h"

class Melee2hLunge1Command : public CombatQueueCommand {
public:

	Melee2hLunge1Command(const String& name, ZoneProcessServer* server)
		: CombatQueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		int result = doCombatAction(creature, target);

		if (result == SUCCESS)
			creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("melee2hlunge1"));

		return result;
	}

};
