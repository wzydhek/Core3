/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class SuiForceClosePage : public BaseMessage {
public:
	SuiForceClosePage(uint32 pageID);

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
