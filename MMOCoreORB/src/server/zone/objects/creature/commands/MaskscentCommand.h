/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class MaskscentCommand : public QueueCommand {
public:
	MaskscentCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool toggleMaskScent(CreatureObject* player) const;

	bool checkMaskScent(CreatureObject* creature) const;
};

