/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class ForceOfWillCommand : public QueueCommand {

	void doDowner(CreatureObject* player, int buffDownerValue, float duration) const;

public:

	ForceOfWillCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

