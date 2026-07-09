/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "JediQueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"

class ForceArmor1Command : public JediQueueCommand {
public:

	ForceArmor1Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const override;

	void handleBuff(SceneObject* sceneObject, ManagedObject* object, int64 param) const override;

};
