/*
 * CraftingExperimentCallback.h
 *
 *  Created on: 10/07/2010
 *      Author: Kyle
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class CraftingExperimentCallback : public MessageCallback {

	int clientCounter;
	int numRowsAttempted;
	String expString;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	CraftingExperimentCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
