/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForcePowersQueueCommand.h"

class ForceLightningCone2Command : public ForcePowersQueueCommand {
public:

	ForceLightningCone2Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};
