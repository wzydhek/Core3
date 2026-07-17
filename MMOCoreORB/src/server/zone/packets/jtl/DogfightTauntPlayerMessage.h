/*
 * DogfightTauntPlayerMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace jtl {

class DogfightTauntPlayerMessage : public BaseMessage {
public:
	DogfightTauntPlayerMessage();

};

} // namespace jtl
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::jtl;
