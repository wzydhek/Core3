/*
 * JtlShipListRequestCallback.h
 *
 *  Created on: 04/25/2011
 *      Author: crush
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class JtlShipListRequestCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;

	uint64 terminalObjectID;

public:
	JtlShipListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
