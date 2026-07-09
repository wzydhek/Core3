/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"

class MoveFurnitureCommand : public QueueCommand {
public:

	MoveFurnitureCommand(const String& name, ZoneProcessServer* server);

	//returns false on collision detection
	bool checkCollision(SceneObject* object, Vector3& endPoint) const;

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

