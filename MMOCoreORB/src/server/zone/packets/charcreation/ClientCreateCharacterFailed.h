/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

//This packet is sent when we verify the data (namely the charname) when the client sends ClientCreateCharacter
//If it fails we are sending the failure notice here:

namespace server {
namespace zone {
namespace packets {
namespace charcreation {

class ClientCreateCharacterFailed : public BaseMessage {
public:
	ClientCreateCharacterFailed(String error_String);
};

} // namespace charcreation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::charcreation;
