/*
 * TeleportAckCallback.h
 *
 *  Created on: 27/11/2010
 *      Author: victor
 */

#pragma once

#include "../MessageCallback.h"
#include "ObjectControllerMessageCallback.h"

class TeleportAckCallback : public MessageCallback {
	uint32 movementCounter;
	ObjectControllerMessageCallback* objectControllerMain;

public:
	TeleportAckCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
