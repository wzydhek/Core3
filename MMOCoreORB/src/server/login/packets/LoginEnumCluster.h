/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace login {
namespace packets {

class LoginEnumCluster : public BaseMessage {
protected:
	int galaxyCount;
public:
	LoginEnumCluster(uint32 galcnt);

	LoginEnumCluster* clone();

	void addGalaxy(uint32 gid, const String& name);

	void finish();

	static void parse(Packet* pack);

};

}
}
}

using namespace server::login::packets;
