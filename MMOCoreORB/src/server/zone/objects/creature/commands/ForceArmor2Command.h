/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "JediQueueCommand.h"

class ForceArmor2Command : public JediQueueCommand {
public:

	ForceArmor2Command(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const override;

	void handleBuff(SceneObject* sceneObject, ManagedObject* object, int64 param) const override;

};
