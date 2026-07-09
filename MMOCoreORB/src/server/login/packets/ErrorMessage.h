/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ErrorMessage : public BaseMessage {
public:
	ErrorMessage(const String& errorType, const String& errorMsg, uint8 fatal);
};
