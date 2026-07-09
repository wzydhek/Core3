/*
 * ItemDropTradeCallback.h
 *
 *  Created on: 07/06/2010
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessageCallback.h"


class ItemDropTradeCallback : public MessageCallback {
	uint64 targetToTrade;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	ItemDropTradeCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
