/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class UnAcceptTransactionMessage : public BaseMessage {
public:
	UnAcceptTransactionMessage() : BaseMessage(6) {
		insertShort(1);
		insertInt(0xE81E4382);
	}
};
