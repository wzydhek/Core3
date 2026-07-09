/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class RotateFurnitureCommand : public QueueCommand {
public:

	RotateFurnitureCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool isValidMoveable(CreatureObject* player, SceneObject* object, bool rotateYaw, bool rotatePitch, bool rotateRoll, bool resetRotate, bool enhancedRotate) const;

};

