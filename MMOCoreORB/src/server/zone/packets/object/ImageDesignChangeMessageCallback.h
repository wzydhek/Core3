/*
 * ImageDesignChangeMessageCallback.h
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

class ImageDesignChangeMessageCallback : public MessageCallback {
	uint64 designerID;
	uint64 targetID;
	uint64 tentID;
	uint8 type;

	ObjectControllerMessageCallback* objectControllerMain;

	ImageDesignData imageDesignData;

public:
	ImageDesignChangeMessageCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
