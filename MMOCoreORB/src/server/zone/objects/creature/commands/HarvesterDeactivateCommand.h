/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class HarvesterDeactivateCommand : public QueueCommand {
public:
	HarvesterDeactivateCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

