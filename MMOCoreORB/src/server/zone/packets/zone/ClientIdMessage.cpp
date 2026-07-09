#include "ClientIdMessage.h"

ClientIdMessage::ClientIdMessage(uint32 accountID, const String& sessionID) : BaseMessage() {
	insertShort(0x03);
	insertInt(STRING_HASHCODE("ClientIdMsg"));

	insertInt(0xFE);				   // gameBits
	insertInt(sessionID.length() + 4); // dataLen (sessionID length + 4 for accountID)

	// Insert sessionID as bytes
	for (const auto val : sessionID) {
		insertByte(val);
	}

	insertInt(accountID);		   // Account ID
	insertAscii("20050408-18:00"); // Client version
}