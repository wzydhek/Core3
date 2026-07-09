/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class BandFlourishCommand : public QueueCommand {
public:

	BandFlourishCommand(const String& name, ZoneProcessServer* server);

	static bool doBandFlourish(CreatureObject* player, int flourishNum, String& instrumentName);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

};
