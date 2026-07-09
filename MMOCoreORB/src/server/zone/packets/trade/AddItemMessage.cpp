#include "AddItemMessage.h"

AddItemMessage::AddItemMessage(uint64 itemID) : BaseMessage(14) {
	insertShort(1);
	insertInt(0x1E8D1356);
	insertLong(itemID);
}