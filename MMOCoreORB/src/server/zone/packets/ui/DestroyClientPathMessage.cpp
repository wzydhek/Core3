#include "DestroyClientPathMessage.h"

DestroyClientPathMessage::DestroyClientPathMessage() : BaseMessage() {
	insertShort(0x01);
	insertInt(0xA75E85EB); // CRC

	// Destroys the path
}