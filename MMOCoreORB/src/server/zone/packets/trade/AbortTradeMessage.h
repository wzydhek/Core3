/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class AbortTradeMessage : public BaseMessage {
public:
	AbortTradeMessage() : BaseMessage(6) {
		insertShort(1);
		insertInt(0x9CA80F98);
	}
};
