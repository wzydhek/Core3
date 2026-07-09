#include "ClientCreateCharacterFailed.h"

ClientCreateCharacterFailed::ClientCreateCharacterFailed(String error_String) : BaseMessage() {
	insertShort(0x03);
	insertInt(0xDF333C6E);	 // opcode: ClientCreateCharacterFailed
	insertInt(0x00);		 // Unicode String, used instead of stf file. We'll never use it.
	insertAscii("ui", 0x02); // ui file used for the client to pull the error message from - static
	insertInt(0x00);		 // static spacer
	insertAscii(error_String);
	// Please note, error_String must be a specefic error String from table.
	// See: ClientCreateCharacterFailed

	setCompression(false);
}