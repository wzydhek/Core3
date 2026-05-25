/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class DestroyCommand : public QueueCommand {
public:

	DestroyCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		//Note: This command doesn't do anything...

		return SUCCESS;
	}

};
