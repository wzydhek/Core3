/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediCombatQueueCommand.h"

class SaberPolearmHit1Command : public JediCombatQueueCommand {
public:

	SaberPolearmHit1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
