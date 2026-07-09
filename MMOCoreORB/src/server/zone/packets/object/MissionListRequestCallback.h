/*
 * MissionListRequestCallback.h
 *
 *  Created on: 30/01/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class MissionListRequestCallback : public MessageCallback {
	uint16 flags;
	uint16 seq;
	uint64 terminalObjectID;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	MissionListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

};
