/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#pragma once

#include "ObjectControllerMessageCallback.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/variables/Ability.h"
#include "server/zone/objects/tangible/misc/DroidProgrammingChip.h"


#define DEBUG_DROID_COMMAND

class DroidCommandProgrammingCallback : public MessageCallback {
protected:
	ObjectControllerMessageCallback* objectControllerMain;

	Vector<String> commandsToAdd;
	Vector<uint64> modulesToAdd;
	Vector<uint64> modulesToRemove;
	uint64 controlDeviceID;

public:
	DroidCommandProgrammingCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

	void addCommand(ZoneServer* zoneServer, SceneObject* datapad, Ability* ability, float dataSize);

	void addModuleFromInventory(ZoneServer* zoneServer, SceneObject* datapad, DroidProgrammingChip* programmedModule);

	bool hasCommand(SceneObject* datapad, String commandName);

	bool hasSpaceForCommand(SceneObject* datapad, int capacity, int commandSize);
};
