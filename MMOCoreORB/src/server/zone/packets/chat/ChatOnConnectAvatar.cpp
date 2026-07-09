#include "ChatOnConnectAvatar.h"

ChatOnConnectAvatar::ChatOnConnectAvatar() : BaseMessage() {
	insertShort(0x01);
	insertInt(0xD72FE9BE); // CRC
}