/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

class FindMyTrainerCommand : public QueueCommand {
public:
	FindMyTrainerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void setJediTrainer(ZoneServer* zoneServer, PlayerObject* ghost) const;
};

