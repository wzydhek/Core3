/*
 * IsFlattenedTheaterMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class IsFlattenedTheaterMessage : public BaseMessage {
public:
	IsFlattenedTheaterMessage(uint64 objectID, bool shouldFlatten);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
