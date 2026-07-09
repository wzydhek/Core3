/*
 * MissionAbortCallback.h
 *
 *  Created on: 22/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"


class MissionAbortCallback : public MessageCallback {
	uint64 missionObjectID;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	MissionAbortCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
