/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class SetFactionStandingCommand : public QueueCommand {
public:

	SetFactionStandingCommand(const String& name, ZoneProcessServer* server);

	void sendInvalidParameterMessage(CreatureObject* creature) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

