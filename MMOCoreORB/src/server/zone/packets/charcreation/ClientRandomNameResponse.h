/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ClientRandomNameResponse : public BaseMessage {
public:
	ClientRandomNameResponse(String raceIff, String name);
	
};
