/*
 * CraftingAddIngredientCallback.h
 *
 *  Created on: 10/07/2010
 *      Author: Kyle
 */

#pragma once

#include "ObjectControllerMessageCallback.h"


class CraftingAddIngredientCallback : public MessageCallback {
	uint64 objectID;
	int slot;
	int counter;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	CraftingAddIngredientCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
