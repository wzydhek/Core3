#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/sui/SuiPageData.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class SuiUpdatePageMessage : public BaseMessage {

public:
	SuiUpdatePageMessage(SuiPageData* sui);
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
