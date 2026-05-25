/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class ItemmovebackCommand : public QueueCommand {
public:

	ItemmovebackCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		creature->executeObjectControllerAction(0x4B74A403, target, "back 10");

		return SUCCESS;
	}

};
