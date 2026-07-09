/*
 * LotteryWindowCallback.h
 *
 *  Created on: Mar 16, 2015
 *      Author: swgemu
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"
#include "ObjectControllerMessageCallback.h"

class LotteryWindowCallback : public MessageCallback {
	uint64 containerID;

	uint32 listSize;
	Vector<uint64> lootIDs;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	LotteryWindowCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* msg);

	void run();
};
