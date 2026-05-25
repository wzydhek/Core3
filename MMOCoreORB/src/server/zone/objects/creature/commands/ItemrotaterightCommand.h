/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class ItemrotaterightCommand : public QueueCommand {
public:

	ItemrotaterightCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		creature->executeObjectControllerAction(0xA8EB1D48, target, "right 45");

		return SUCCESS;
	}

};
