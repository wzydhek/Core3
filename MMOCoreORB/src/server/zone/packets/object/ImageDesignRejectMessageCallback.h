/*
 * ImageDesignRejectMessageCallback.h
 *
 *  Created on: 02/02/2011
 *      Author: Polonel
 */

#pragma once

#include "ObjectControllerMessageCallback.h"
#include "server/zone/objects/player/sessions/ImageDesignData.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ImageDesignRejectMessageCallback : public MessageCallback {
	uint64 designer;
	uint64 target;
	uint64 tent;
	uint8 type;

	ImageDesignData data;

	ObjectControllerMessageCallback* objectControllerMain;

public:
	ImageDesignRejectMessageCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
