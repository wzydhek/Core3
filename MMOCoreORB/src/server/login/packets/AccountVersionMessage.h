/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace login {
namespace packets {

class AccountVersionMessage : public BaseMessage {

public:
	AccountVersionMessage(const String& username, const String& password, const String& version);

	static void parse(Packet* pack, String& username, String& password, String& version);

};

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;
