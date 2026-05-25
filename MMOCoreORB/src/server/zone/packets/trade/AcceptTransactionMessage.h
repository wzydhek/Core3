/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class AcceptTransactionMessage : public BaseMessage {
public:
	AcceptTransactionMessage() : BaseMessage(6) {
		insertShort(1);
		insertInt(0xB131CA17);
	}
};
