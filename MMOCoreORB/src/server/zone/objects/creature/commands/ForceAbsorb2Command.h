/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"

class ForceAbsorb2Command : public JediQueueCommand {
public:

	ForceAbsorb2Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const override;

	void handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const override;
};
