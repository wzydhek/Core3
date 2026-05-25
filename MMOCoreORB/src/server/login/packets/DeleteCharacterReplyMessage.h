/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class DeleteCharacterReplyMessage : public BaseMessage {
public:
	DeleteCharacterReplyMessage(int Failure) : BaseMessage() {
		insertShort(0x03);
		insertInt(0x8268989B); //DeleteCharacterReplyMessage
		insertInt(Failure);
      }
};
