/*
 * EmptyHopperCallback.h
 *
 *  Created on: 14/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class EmptyHopperCallback : public MessageCallback {
	uint64 harvesterId;
	uint64 resourceId;
	uint32 quantity;
	uint8 byte1;
	uint8 byte2;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	EmptyHopperCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
