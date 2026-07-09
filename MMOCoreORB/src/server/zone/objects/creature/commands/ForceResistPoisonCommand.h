/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"

class ForceResistPoisonCommand : public JediQueueCommand {
public:

	ForceResistPoisonCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
