/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class TradeCompleteMessage : public BaseMessage {
public:
	TradeCompleteMessage() : BaseMessage(0x06) {
		insertShort(0x01);
		insertInt(0xC542038B);
	}
};
