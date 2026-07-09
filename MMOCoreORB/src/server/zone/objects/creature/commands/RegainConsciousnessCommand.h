/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"

class RegainConsciousnessCommand : public JediQueueCommand {
public:

	RegainConsciousnessCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
