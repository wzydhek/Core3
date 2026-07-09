/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class SuiForceClosePage : public BaseMessage {
public:
	SuiForceClosePage(uint32 pageID);

};
