/*
 * CraftingRemoveIngredientCallback.h
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

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
