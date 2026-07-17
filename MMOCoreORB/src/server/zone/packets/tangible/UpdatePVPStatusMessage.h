/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class UpdatePVPStatusMessage : public BaseMessage {
public:
	UpdatePVPStatusMessage(TangibleObject* tano);

	UpdatePVPStatusMessage(TangibleObject* tano, TangibleObject* receiver, uint32 pvpStatusBitmask);
};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
