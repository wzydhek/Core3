/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

//This packet is sent when we verify the data (namely the charname) when the client sends ClientCreateCharacter
//We are assigning an object id here. after this packet, continue with the ZONELOGIN sequence as usual

namespace server {
namespace zone {
namespace packets {
namespace charcreation {

class ClientCreateCharacterSuccess : public BaseMessage {
public:
	ClientCreateCharacterSuccess(uint64 objid);

};

} // namespace charcreation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::charcreation;
