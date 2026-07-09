/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class SitServerCommand : public QueueCommand {
public:
	const static int MINDELTA = 1600;

	SitServerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int setPlayerPosture(CreatureObject* creature) const;
};

