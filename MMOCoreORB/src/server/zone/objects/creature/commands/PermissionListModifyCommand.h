/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"

class PermissionListModifyCommand : public QueueCommand {
public:
	PermissionListModifyCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int handleStructurePermissions(CreatureObject* creature, SceneObject* sceneO, String targetName, String listName, String action, String arguments) const;

	int handlePobShipPermissions(CreatureObject* creature, SceneObject* sceneO, String targetName, String listName, String action, String arguments) const;
};

