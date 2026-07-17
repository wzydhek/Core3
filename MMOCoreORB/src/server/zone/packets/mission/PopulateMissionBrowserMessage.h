/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace mission {

class PopulateMissionBrowserMessage : public BaseMessage {
public:
	PopulateMissionBrowserMessage();
};

} // namespace mission
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::mission;
