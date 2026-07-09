/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class DeleteCharacterReplyMessage : public BaseMessage {
public:
	DeleteCharacterReplyMessage(int Failure);
};
