/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SquadLeaderCommand.h"

class SetRetreatCommand : public SquadLeaderCommand {
public:

	SetRetreatCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, /*Skill* skill,*/ const uint64& target, const UnicodeString& arguments) const;

};
