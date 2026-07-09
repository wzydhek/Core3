#include "LoginClientToken.h"

LoginClientToken::LoginClientToken(const String& username, const String& sessionToken, uint32 accountid, uint32 stationid) : BaseMessage() {
	insertShort(0x04);
	insertInt(STRING_HASHCODE("LoginClientToken"));

	insertInt(sessionToken.length() + 4); // embedding accountid

	for (const auto val : sessionToken) {
		insertByte(val);
	}

	insertInt(accountid);

	insertInt(stationid);
	insertAscii(username); // Station Account Name
}

LoginClientToken::LoginClientToken(Account* account, const String& sessionToken) : BaseMessage() {
	insertShort(0x04);
	insertInt(STRING_HASHCODE("LoginClientToken"));

	insertInt(sessionToken.length() + 4);

	for (const auto val : sessionToken) {
		insertByte(val);
	}

	insertInt(account->getAccountID());

	insertInt(account->getStationID());
	insertAscii(account->getUsername());
}

void LoginClientToken::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}