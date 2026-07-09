/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ClientPermissionsMessage : public BaseMessage {
public:
	ClientPermissionsMessage();

	ClientPermissionsMessage(bool canConnect, bool canCreateCharacter);
};
