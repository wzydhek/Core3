/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/login/account/Account.h"
#include "../objects/CharacterList.h"

namespace server {
namespace login {
namespace packets {

class EnumerateCharacterId : public BaseMessage {
public:
	EnumerateCharacterId(Account* account);

	static void parse(Packet* pack);

};

} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;
