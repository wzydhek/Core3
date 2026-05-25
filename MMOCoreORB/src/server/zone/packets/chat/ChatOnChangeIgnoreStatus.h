/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnChangeIgnoreStatus : public BaseMessage {
public:
	ChatOnChangeIgnoreStatus(uint64 oid, const String& name, const String& server, bool add) : BaseMessage() {

		insertShort(0x06);
		insertInt(0x70E9DA0F);  // CRC
		insertLong(oid);

		insertAscii("SWG");
		insertAscii(server);
		insertAscii(name);

		insertInt(0);
		insertByte(add);
		insertInt(0);
	}

};
