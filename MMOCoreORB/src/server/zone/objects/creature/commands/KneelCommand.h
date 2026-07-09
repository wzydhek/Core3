/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class KneelCommand : public QueueCommand {
public:
	const static int MINDELTA = 800;

	KneelCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int setAiAgentPosture(CreatureObject* creature) const;

	int setPlayerPosture(CreatureObject* creature) const;
};

