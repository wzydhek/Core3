/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

class GiveMoneyMessage : public BaseMessage {
public:
	GiveMoneyMessage(uint32 money) : BaseMessage(10) {
		insertShort(2);
		insertInt(0xD1527EE8);
		insertInt(money);
	}
};
