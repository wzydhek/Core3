/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class GetVeteranRewardTimeCommand : public QueueCommand {
public:
	GetVeteranRewardTimeCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* player, const uint64& target, const UnicodeString& arguments) const;
};

