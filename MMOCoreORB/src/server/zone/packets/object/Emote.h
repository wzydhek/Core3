/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class Emote : public ObjectControllerMessage {
public:
	Emote(uint64 senderID, uint64 targetID, uint64 emoteTargetID, uint32 emoteID, bool doAnim = true, bool doText = true);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
