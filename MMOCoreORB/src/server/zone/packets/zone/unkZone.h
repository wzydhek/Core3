/*
 * unkZone.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

 // test

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class unkZone : public BaseMessage {
public:
	unkZone();

};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
