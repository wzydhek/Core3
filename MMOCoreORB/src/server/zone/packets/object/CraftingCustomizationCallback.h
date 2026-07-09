/*
 * CraftingAddIngredientCallback.h
 *
 *  Created on: 10/07/2010
 *      Author: Kyle
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

class CraftingCustomizationCallback : public MessageCallback {
	String name;
	String customizationString;
	int schematicCount;
	int counter;
	byte templateChoice;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	CraftingCustomizationCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
