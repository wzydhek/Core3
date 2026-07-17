/*
 * CraftingAddIngredientCallback.h
 *
 *  Created on: 10/07/2010
 *      Author: Kyle
 */

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

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

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
