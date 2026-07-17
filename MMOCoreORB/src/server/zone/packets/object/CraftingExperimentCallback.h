/*
 * CraftingExperimentCallback.h
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

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
