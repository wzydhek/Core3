/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/Zone.h"

class ServerTimeMessage : public BaseMessage {
public:
	ServerTimeMessage(uint64 time);
	
	ServerTimeMessage(Zone* zone);
	
};
