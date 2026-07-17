//
// Created by g on 12/20/17.
//

#pragma once

#include "ObjectControllerMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class OrientForHyperspaceMessage : public ObjectControllerMessage {
public:
	OrientForHyperspaceMessage(uint64 objid, const String& zone, float x, float y, float z);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
