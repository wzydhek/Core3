#include "ConnectionServerTestMessage.h"

ConnectionServerTestMessage::ConnectionServerTestMessage() : BaseMessage() {
	insertShort(0x02);
	insertInt(0x0E20D7E9);

	insertAscii("ConnectionServer:1348");
}