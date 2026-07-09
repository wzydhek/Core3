/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace login {
namespace packets {

class LoginClusterStatus : public BaseMessage {
protected:
	int galaxyCount;
public:
	LoginClusterStatus(uint32 galcnt);

	LoginClusterStatus* clone();

	void addGalaxy(uint32 gid, const String& address, uint16 port, uint16 pingport);

	static void parse(Packet* pack);
};

}
}
}

using namespace server::login::packets;
