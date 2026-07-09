/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class RecruitSkillTrainerCommand : public QueueCommand {
public:

	RecruitSkillTrainerCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

