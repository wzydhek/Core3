/*
 * CraftingRemoveIngredientCallback.h
 *
 *  Created on: 10/07/2010
 *      Author: Kyle
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class CraftingRemoveIngredientCallback : public MessageCallback {
	uint64 objectID;
	int slot;
	int counter;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	CraftingRemoveIngredientCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
