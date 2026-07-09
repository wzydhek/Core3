/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/login/account/Account.h"

namespace server {
namespace login {

namespace account {
class Account;
}

using namespace server::login::account;

namespace packets {

class LoginClientToken : public BaseMessage {
public:
	LoginClientToken(const String& username, const String& sessionToken, uint32 accountid, uint32 stationid);

	LoginClientToken(Account* account, const String& sessionToken);

	static void parse(Packet* pack);
};
} // namespace packets
} // namespace login
} // namespace server

using namespace server::login::packets;
