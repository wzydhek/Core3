#include "ChatOnAddFriend.h"

ChatOnAddFriend::ChatOnAddFriend() : BaseMessage() {
	insertShort(0x03);
	insertInt(0x2B2A0D94); // CRC
	insertLong(0);
}