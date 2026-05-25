/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class AssignDroidCommand : public QueueCommand {
public:

	AssignDroidCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		return SUCCESS;
	}

};
