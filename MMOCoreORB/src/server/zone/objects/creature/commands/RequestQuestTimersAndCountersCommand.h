/*
 * RequestQuestTimersAndCountersCommand.h
 *
 *  Created on: Oct 6, 2010
 *      Author: oru
 */

#pragma once

class RequestQuestTimersAndCountersCommand : public QueueCommand {
public:

	RequestQuestTimersAndCountersCommand(const String& name, ZoneProcessServer* server)
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
