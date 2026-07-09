/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class RequestSurveyCommand : public QueueCommand {
public:

	RequestSurveyCommand(const String& name, ZoneProcessServer* server);

	/**
	 * Regardless of what is entered as arguments in the client, the client
	 * sends the name of the resource surveyed for as the only argument.
	 * This is always handled by the client as long as a tool has been
	 * used during the current play session.
	 */

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

