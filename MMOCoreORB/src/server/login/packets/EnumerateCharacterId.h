/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/login/account/Account.h"
#include "../objects/CharacterList.h"

class EnumerateCharacterId : public BaseMessage {
public:
	EnumerateCharacterId(Account* account);

	static void parse(Packet* pack);

};
