/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "QueueCommand.h"

class GmReviveCommand : public QueueCommand {
public:

	GmReviveCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	void revivePatient(CreatureObject* creature, CreatureObject* patient) const;

	void repairShip(CreatureObject* player, SceneObject* shipSceneO) const;
};

