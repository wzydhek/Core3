/*
 * MissionAcceptCallback.h
 *
 *  Created on: 22/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class MissionAcceptCallback : public MessageCallback {
	uint64 missionObjectID;
	uint64 terminalObjectID;
	uint8 terminalIndex;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	MissionAcceptCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
